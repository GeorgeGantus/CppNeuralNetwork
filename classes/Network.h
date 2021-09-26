#include <vector>

#include "Layer.h"
class Network {
   private:
    vector<Layer> layers;
    int numInputs;

   public:
    Network(int numInputs);
    void build();
    void addLayers(Layer layer);
};