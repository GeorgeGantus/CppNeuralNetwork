#include <iostream>
#include <vector>

#include "classes/Layer.h"
#include "classes/Matrix.h"
#include "classes/Network.h"
using namespace std;
int main() {
    Layer l1(2);
    Layer l2(2);
    Network net(2);
    net.addLayers(l1);
    net.addLayers(l2);
    net.build();

    Matrix input(1, 2);
    input.data[0][0] = 1;
    input.data[0][1] = 1;

    Matrix teste(2, 2);
    Matrix a = input.matricialMultiplication(teste);
    a.print();
    /* net.build();
    net._compute(input); */
}