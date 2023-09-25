#include "IntCell.h"

// Default constructor
IntCell::IntCell(int newValue) : storedValue(newValue) {}

// Copy constructor
IntCell::IntCell(const IntCell &rhs) : storedValue(rhs.storedValue) {}

// Move constructor
IntCell::IntCell(IntCell &&rhs) noexcept : storedValue(rhs.storedValue) {
   // rhs.storedValue = 0;
}
// Copy assignment operator
IntCell &IntCell::operator=(const IntCell &rhs) {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
    }
    return *this;
}

// Remove Move assignment operator
IntCell &IntCell::operator=(IntCell &&rhs) noexcept {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}

// Overloaded assignment operator to accept only integer data
IntCell &IntCell::operator=(int rhs) {
    storedValue = rhs;
    return *this;
}

// getters and setters
// getter
int IntCell::getValue(int i) const {
    return storedValue;
}
// setter
void IntCell::setValue(int newValue) {
    storedValue =newValue;
}