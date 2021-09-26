#include "Layer.h"

Layer::Layer(int numNeurons) {
    this->numNeurons = numNeurons;
}

void Layer::setNumInputs(int numInputs) {
    this->numInputs = numInputs;
}

int Layer::getNumNeurons() {
    return numNeurons;
}

vector<float> Layer::output(vector<float> inputs) {
    vector<Neuron>::iterator neuron;
    vector<float> out;
    for (neuron = neurons.begin(); neuron < neurons.end(); neuron++) {
        out.push_back((*neuron).output(inputs));
    }
    return out;
}