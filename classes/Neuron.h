#include <vector>
using namespace std;

class Neuron {
   private:
    float bias;
    vector<float> weights;

   public:
    Neuron(int inputNumber, int seed);
    float output(vector<float> inputs);
    void print();
};