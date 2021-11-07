#include "Network.h"

#include <math.h>

#include <iostream>

vector<float> Network::_softmax(vector<float> input) {
    vector<float> output;
    vector<float>::iterator i;
    float sum = 0;
    for (i = input.begin(); i < input.end(); i++) {
        sum += exp(*i);
    }
    for (i = input.begin(); i < input.end(); i++) {
        output.push_back(exp(*i) / sum);
    }
    return output;
}

Network::Network(int numInputs) {
    this->numInputs = numInputs;
}

void Network::addLayers(Layer layer) {
    if (layers.empty()) {
        layer.setNumInputs(numInputs);
    } else {
        layer.setNumInputs(layers.back().getNumNeurons());
    }
    layers.push_back(layer);
}

void Network::build() {
    vector<Layer>::iterator ptr;
    if (layers[layers.size() - 1].getNumNeurons() != 1) {
        cout << "ERROR: models with more than one output are under development"
             << "\n";
        return;
    }

    for (ptr = layers.begin(); ptr < layers.end(); ptr++) {
        (*ptr).build();
    }
}

vector<float> Network::_compute(vector<float> input) {
    vector<Layer>::iterator layer;
    for (layer = layers.begin(); layer < layers.end(); layer++) {
        input = (*layer).output(input)[0];
    }
    return input;
}

float Network::_getBatchCrossEntropyError(vector<vector<float>> X, vector<vector<int>> Y) {
    vector<vector<float>>::iterator input;
    vector<vector<int>>::iterator target;
    vector<float> output;
    float meanError = 0;
    for (input = X.begin(), target = Y.begin(); input < X.end(); input++, target++) {
        output = _softmax(_compute(*input));
        float error = 0;
        for (int i = 0; i < output.size(); i++) {
            /* code */
            error += log2(output[i]) * (*target)[i];
        }
        meanError += error;
    }
    meanError = meanError / Y.size();
    return meanError;
}

float Network::_getBatchMeanSquaredError(vector<vector<float>> X, vector<float> Y) {
    vector<vector<float>>::iterator input;
    vector<float>::iterator target;
    vector<float> output;
    float meanError = 0;
    for (input = X.begin(), target = Y.begin(); input < X.end(); input++, target++) {
        output = _compute(*input);
        meanError += pow((*target - output[0]), 2) / 2;
    }
    meanError = meanError / Y.size();
    return meanError;
}
void Network::print() {
    vector<Layer>::iterator layer;
    cout << "**********Network**********" << endl;
    cout << endl;
    for (layer = layers.begin(); layer < layers.end(); layer++) {
        (*layer).print();
    }
}
