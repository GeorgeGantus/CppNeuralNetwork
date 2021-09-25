#include <vector>

#include "Neuron.h"
using namespace std;
class Layer {
   private:
    int numNeurons;
    vector<float> inputs;
    vector<Neuron> neurons;

   public:
    Layer(int numNeurons);
};