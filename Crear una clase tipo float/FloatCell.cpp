#include "FloatCell.h"

// default constructor
// :: que solo lo modifica Floatcell
// : que accede a ese espacio
FloatCell::FloatCell(float newValue) : storeValue(newValue){}

// copy constructor
FloatCell::FloatCell(const FloatCell & rhs) : storeValue(rhs.storeValue){}
// con
// construtor por referencia
FloatCell::FloatCell( FloatCell &&rhs) noexcept : storeValue(rhs.storeValue){
    rhs.storeValue = 0 ;
}

// copy assigment operator
FloatCell &FloatCell ::operator=(const FloatCell &rhs) {
    if (this != &rhs){
        storeValue = rhs.storeValue;
    }
    return *this;
}
// aqui vas puñetas
FloatCell &FloatCell::operator=(FloatCell &&rhs) noexcept {
    if(this != &rhs){
        storeValue = rhs.storeValue;
        rhs.storeValue = 0;
    }
    return *this;
}
FloatCell &FloatCell::operator=(float rhs){
    storeValue = rhs;
    return *this;
}
FloatCell &FloatCell::operator+(const FloatCell &rhs)
{
    storeValue =  storeValue + rhs.storeValue;
    return *this;
}

//getters an setters
//get stored value
float  FloatCell::getValue() const {
    return  storeValue;
}
//set stored value
void FloatCell::SetValue(float newValue) {
    storeValue = newValue;
}