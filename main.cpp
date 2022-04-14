#include <iostream>
#include <vector>

#include "classes/Matrix.h"
using namespace std;
int main() {
    /* Layer layer1(2);
    Network network(2);
    network.addLayers(layer1);
    network.build();
    network.print();
    cout << "ok"; */
    Matrix m1(2, 2);
    m1.data[1][1] = 2;
    m1.data[0][0] = 1;
    m1.data[0][1] = 1;
    m1.print();
    //m1.scalarMultiplication(2.5);
    Matrix m2(2, 2);
    m2.data[0][1] = 1;
    m2.data[1][0] = 1;
    m2.data[1][1] = 1;
    m2.print();

    Matrix m3 = m1.matricialMultiplication(m2);
    m3.print();
}