#include <iostream>
#include "FloatCell.h"

int main() {
FloatCell a;
float aux;

std::cout << " ingrese su dato:"<<std::endl;
std::cin >> aux;
a.SetValue(aux);

    std::cout << a.getValue()<<std::endl;
    std::cout << aux <<std::endl;

    return 0;
}
