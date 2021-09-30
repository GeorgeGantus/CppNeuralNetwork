#include "Network.h"

#include <math.h>

#include <iostream>
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
    for (ptr = layers.begin(); ptr < layers.end(); ptr++) {
        (*ptr).build();
    }
}

vector<float> Network::_compute(vector<float> input) {
    vector<Layer>::iterator layer;
    for (layer = layers.begin(); layer < layers.end(); layer++) {
        input = (*layer).output(input);
    }
    return input;
}

float Network::_getBatchCrossEntropyError(vector<vector<float>> X, vector<vector<int>> Y) {
    vector<vector<float>>::iterator input;
    vector<vector<int>>::iterator target;
    vector<float> output;
    float meanError = 0;
    for (input = X.begin(), target = Y.begin(); input < X.end(); input++, target++) {
        output = _compute(*input);
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
void Network::print() {
    vector<Layer>::iterator layer;
    cout << "**********Network**********" << endl;
    cout << endl;
    for (layer = layers.begin(); layer < layers.end(); layer++) {
        (*layer).print();
    }
}