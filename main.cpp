#include <iostream>
#include <vector>

#include "classes/Network.h"
using namespace std;
int main() {
    Layer layer1(2);
    Network network(2);
    network.addLayers(layer1);
    network.build();
    network.print();
    cout << "ok";
}