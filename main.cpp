#include <iostream>
#include <vector>

#include "classes/Neuron.h"
using namespace std;
int main() {
    vector<float> v;
    v.push_back(1);
    v.push_back(1);

    Neuron n1(2, 13123);
    cout << n1.output(v);
}