#include <vector>

#include "Layer.h"
class Network {
   private:
    vector<Layer> layers;

   public:
    void build();
    void addLayers(Layer layer);
};