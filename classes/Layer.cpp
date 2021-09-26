#include "Layer.h"

Layer::Layer(int numNeurons) {
    this->numNeurons = numNeurons;
}

void Layer::setNumInputs(int numInputs) {
    this->numInputs = numInputs;
}