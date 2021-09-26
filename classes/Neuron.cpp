#include "Neuron.h"

#include <stdlib.h>

#include <iostream>
#include <vector>
using namespace std;
Neuron::Neuron(int inputNumber, int seed) {
    srand(seed);
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
    //Activation = relu
    if (sum >= 0)
        return sum;
    else
        return 0;
}
