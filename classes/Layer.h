#include <vector>

#include "Neuron.h"
using namespace std;
class Layer {
   private:
    int numNeurons;
    int numInputs;
    vector<Neuron> neurons;

   public:
    Layer(int numNeurons);
    vector<float> output(vector<float> inputs);
    void setNumInputs(int numInputs);
};