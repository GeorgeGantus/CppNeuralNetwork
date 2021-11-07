#include <vector>

#include "../helper/globals.h"
#include "Neuron.h"
using namespace std;
class Layer {
   private:
    int numNeurons;
    int numInputs;
    vector<Neuron> neurons;
    vector<vector<float>> weightMatrix;

   public:
    Layer(int numNeurons);
    vector<vector<float>> output(vector<float> inputs);
    void setNumInputs(int numInputs);
    int getNumNeurons();
    void build();
    void print();
};