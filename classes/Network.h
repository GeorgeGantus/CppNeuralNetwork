#pragma once
#include <vector>

#include "Layer.h"
#include "Matrix.h"

class Network {
   private:
    vector<Layer> layers;
    int numInputs;
    float _getBatchCrossEntropyError(vector<vector<float>> X, vector<vector<int>> Y);
    float _getBatchMeanSquaredError(vector<vector<float>> X, vector<float> Y);
    Matrix _computeLastLayerError(Matrix yHat);

   public:
    Network(int numInputs);
    void build();
    void print();
    void addLayers(Layer &layer);
    Matrix _compute(Matrix &input);
};