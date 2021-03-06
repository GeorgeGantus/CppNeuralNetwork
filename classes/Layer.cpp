#include "Layer.h"

#include <iostream>

#include "../helper/globals.h"

Layer::Layer(int numNeurons) {
    this->numNeurons = numNeurons;
    biasMatrix = Matrix(numNeurons, 1);
}

void Layer::build(int numInNeurons) {
    weightMatrix = Matrix(numNeurons, numInNeurons);
}

Matrix Layer::output(Matrix &input) {
    weightedOutput = input.matricialMultiplication(weightMatrix) + biasMatrix;
    activation = weightedOutput.applyFunc(&sigmoid);
    return activation;
}

int Layer::getNumNeurons() {
    return numNeurons;
}

Matrix Layer::getWeightedOutput() {
    return weightedOutput;
}