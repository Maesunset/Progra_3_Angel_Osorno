#include <iostream>
#include "FloatCell.h"

int main() {
FloatCell a;
FloatCell b;
float aux;

std::cout << " ingrese su dato:"<<std::endl;
std::cin >> aux;
a.SetValue(aux);
b.SetValue(10);

    std::cout << a.getValue()<<std::endl;
    a = a+b;
    std::cout << a.getValue() <<std::endl;

    return 0;
}
