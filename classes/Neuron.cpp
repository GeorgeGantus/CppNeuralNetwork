#include "Neuron.h"

#include <stdlib.h>

#include <iostream>
#include <vector>
using namespace std;
Neuron::Neuron(int inputNumber, int seed) {
    srand(seed);
    bias = 0;
    for (int i = 0; i < inputNumber; i++) {
        float randm = (float)rand() / RAND_MAX;
        randm = (randm - 0.5) * 2;
        weights.push_back(randm);
    }
}

float Neuron::output(vector<float> inputs) {
    float sum = 0;
    for (int i = 0; i < inputs.size(); i++) {
        sum += inputs[i] * weights[i];
    }
    return sum;
}

void Neuron::print() {
    cout << "Neuron" << endl;
    cout << endl;
    cout << "bias: " << bias;
    cout << endl;
    for (int i = 0; i < weights.size(); i++) {
        cout << "weight " << i << ": " << weights[i] << endl;
    }
    cout << endl;
}

vector<float> Neuron::getWeights() {
    return weights;
}