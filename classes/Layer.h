#pragma once
#include <vector>

#include "Matrix.h"
#include "Neuron.h"
using namespace std;
class Layer {
   private:
    int numNeurons;
    Matrix biasMatrix;
    Matrix weightMatrix;
    Matrix weightedOutput;

   public:
    Matrix activation;
    Layer(int numNeurons);
    void build(int numInNeurons);
    Matrix output(Matrix &input);
    int getNumNeurons();
    Matrix getWeightedOutput();
};