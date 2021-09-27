#include "Layer.h"

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

vector<float> Layer::output(vector<float> inputs) {
    vector<Neuron>::iterator neuron;
    vector<float> out;
    for (neuron = neurons.begin(); neuron < neurons.end(); neuron++) {
        out.push_back((*neuron).output(inputs));
    }
    return out;
}