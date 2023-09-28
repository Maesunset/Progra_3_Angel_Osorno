#include "IntCell.h"

// Default constructor, sirve para r valores
IntCell::IntCell(int newValue) : storedValue(newValue) {}

// constructor por copia, sirve para l valores
IntCell::IntCell(const IntCell &rhs) : storedValue(rhs.storedValue) {}

// constructor por movimiento sirve para l valores
IntCell::IntCell(IntCell &&rhs) noexcept : storedValue(rhs.storedValue) {
   // rhs.storedValue = 0;
}
// operador de asignación por copia
IntCell &IntCell::operator=(const IntCell &rhs) {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
    }
    return *this;
}

// operador por asignación de movimiento
IntCell &IntCell::operator=(IntCell &&rhs) noexcept {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}

// operador de asignación que se asegura que solo entren datos de numeros enteros
IntCell &IntCell::operator=(int rhs) {
    storedValue = rhs;
    return *this;
}

// getters and setters
// son para poner valor a la variable y mostrar el valor guardado
// getter
int IntCell::getValue(int i) const {
    return storedValue;
}
// setter
void IntCell::setValue(int newValue) {
    storedValue =newValue;
}