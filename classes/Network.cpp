#include "Network.h"

#include <math.h>

#include <iostream>

#include "globals.h"

Network::Network(int numInputs) {
    this->numInputs = numInputs;
}

void Network::build() {
    int numNeurons = numInputs;
    for (int i = 0; i < layers.size(); i++) {
        layers[i].build(numNeurons);
        numNeurons = layers[i].getNumNeurons();
    }
}

Matrix Network::_compute(Matrix input) {
    Matrix activation = input;
    for (int i = 0; i < layers.size(); i++) {
        layers[i].output(activation);
        activation = layers[i].activation;
    }
}

Matrix Network::_computeLastLayerError(Matrix yHat) {
    Layer last = layers[layers.size() - 1];
    Matrix y = last.activation;
    return (y - yHat) * last.getWeightedOutput().applyFunc(&sigmoidDerivative);
}