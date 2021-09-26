#include "Network.h"

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