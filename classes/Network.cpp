#include "Network.h"

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

void Network::print() {
    vector<Layer>::iterator layer;
    cout << "**********Network**********" << endl;
    cout << endl;
    for (layer = layers.begin(); layer < layers.end(); layer++) {
        (*layer).print();
    }
}