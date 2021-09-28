#include <vector>

#include "Layer.h"
class Network {
   private:
    vector<Layer> layers;
    int numInputs;
    vector<float> _compute(vector<float> input);

   public:
    Network(int numInputs);
    void build();
    void print();
    void addLayers(Layer layer);
};