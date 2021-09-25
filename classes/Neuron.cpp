#include "Neuron.h"

#include <stdlib.h>

#include <vector>
using namespace std;
Neuron::Neuron(int inputNumber, int seed) {
    srand(seed);
    for (int i = 0; i < inputNumber; i++) {
        weights.push_back(rand() / RAND_MAX);
    }
}

float Neuron::output(vector<float> inputs) {
    int sum = 0;
    for (int i = 0; i < inputs.size(); i++) {
        sum += inputs[i] * weights[i];
    }
    //Activation = relu
    if (sum >= 0)
        return sum;
    else
        return 0;
}
