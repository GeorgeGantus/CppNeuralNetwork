#include <vector>

#include "../helper/globals.h"
#include "Matrix.h"
#include "Neuron.h"
using namespace std;
class Layer {
   private:
    int numNeurons;
    Matrix biasMatrix;
    Matrix weightMatrix;
    Matrix weightedOutput;
    Matrix activation;

   public:
    Layer(int numNeurons);
    void build(int numInNeurons);
    Matrix output(Matrix input);
};