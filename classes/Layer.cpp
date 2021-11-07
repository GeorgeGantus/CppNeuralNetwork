#include "Layer.h"

#include <math.h>

#include <iostream>
Layer::Layer(int numNeurons) {
    this->numNeurons = numNeurons;
}

void Layer::setNumInputs(int numInputs) {
    this->numInputs = numInputs;
}

int Layer::getNumNeurons() {
    return numNeurons;
}

void Layer::build() {
    for (int i = 0; i < numNeurons; i++) {
        Neuron n(numInputs, 42);
        neurons.push_back(n);
    }
}

void Layer::print() {
    vector<Neuron>::iterator neuron;
    cout << "----------Layer----------" << endl;
    cout << endl;
    for (neuron = neurons.begin(); neuron < neurons.end(); neuron++) {
        (*neuron).print();
    }
}

vector<vector<float>> Layer::output(vector<float> inputs) {
    vector<Neuron>::iterator neuron;
    vector<float> out;
    vector<float> weightedInputs;
    for (neuron = neurons.begin(); neuron < neurons.end(); neuron++) {
        out.push_back(sigmoid((*neuron).output(inputs)));
        weightedInputs.push_back(1);
    }
    vector<vector<float>> ret;
    ret.push_back(out);
    ret.push_back(weightedInputs);
    return ret;
}

float sigmoid(float x) {
    return 1 / (1 + exp(-1 * x));
}