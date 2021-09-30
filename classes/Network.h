#include <vector>

#include "Layer.h"
class Network {
   private:
    vector<Layer> layers;
    int numInputs;
    float _getBatchCrossEntropyError(vector<vector<float>> X, vector<vector<int>> Y);
    vector<float> _compute(vector<float> input);

   public:
    Network(int numInputs);
    void build();
    void print();
    void addLayers(Layer layer);
};