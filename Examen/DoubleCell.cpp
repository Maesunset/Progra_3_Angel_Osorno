#include "DoubleCell.h"
#include <stdexcept>

// es el constructor base
// Default constructor
DoubleCell::DoubleCell()
    :Storedvalue(0.0){}


// Constructor with value
//es el constructor con valor
DoubleCell::DoubleCell(double value)
    : Storedvalue(value){}

// Copy constructor
//es el constructor por copia
DoubleCell::DoubleCell(const DoubleCell& other)
    : Storedvalue(other.Storedvalue){}

//Reference constructor
// es el constructor por referencia
DoubleCell::DoubleCell( DoubleCell &&rhs) noexcept : Storedvalue(rhs.Storedvalue){
    rhs.Storedvalue = 0;
}
// Destructor
// segun yo aqui no va, nunca lo habia puesto aqui asi que apuesto a equivocarme

// Assignment operator by copy
DoubleCell& DoubleCell::operator=(const DoubleCell& other){
    if (this != &other){
        Storedvalue = other.Storedvalue;
    }
    return *this;
}
// Assignment operator by reference
DoubleCell &DoubleCell::operator=(DoubleCell &&other) noexcept{
    if(this != &other){
        Storedvalue = other.Storedvalue;
        other.Storedvalue = 0;
    }
    return *this;
}

// Assignment operator for double
DoubleCell& DoubleCell::operator=(double value){
            Storedvalue = value;
            return *this;
}
// Arithmetic operators
//dos versiones de sumas
//DoubleCell adding
DoubleCell DoubleCell::operator +(const DoubleCell& other) const{
    return DoubleCell(Storedvalue + other.Storedvalue);
}
//primitive double adding
DoubleCell DoubleCell::operator+(const double other) const {
    return DoubleCell(Storedvalue + other);
}
// dos versiones de resta
//DoubleCell substracting
DoubleCell DoubleCell::operator -(const DoubleCell& other) const {
    return DoubleCell(Storedvalue - other.Storedvalue);
}
//primitive double substracting
DoubleCell DoubleCell::operator -(double value) const{
    return DoubleCell(Storedvalue - value);
}
// dos versiones de multiplication
//DoubleCell multiplication
DoubleCell DoubleCell::operator *(const DoubleCell& other) const{
    return DoubleCell(Storedvalue * other.Storedvalue);
}
//primitive double multiplication
DoubleCell DoubleCell::operator *(double value) const {
    return DoubleCell(Storedvalue * value);
}
// dos versiones de division
//DoubleCell division
DoubleCell DoubleCell::operator /(const DoubleCell& other) const{
    if(other.Storedvalue == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(Storedvalue / other.Storedvalue);
}

//Primitive double division
DoubleCell DoubleCell::operator /(double value) const{
    if(value == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(Storedvalue / value);
}
// son para ingresar el valor y ver el valor guardado
// Setters
void DoubleCell::SetValue(double newValue){
            Storedvalue = newValue;
}
// Getters
double DoubleCell::GetValue() const {
    return Storedvalue;
}