#include <iostream>
#include "IntCell.h"

int main()
{
    IntCell intCell;
    int x;
    std::cout << " e creado una clase mmlona" << std::endl;
    std::cout << "ingrese un numero" << std::endl;
    std::cin >>  x;
    intCell.setValue(x);

    std::cout << "El valor guardado en InteCell es: "<< intCell.getValue(x)<<std::endl;

}
