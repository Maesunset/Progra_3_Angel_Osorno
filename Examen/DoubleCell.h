#ifndef DOUBLE_CELL_H
#define DOUBLE_CELL_H

class DoubleCell {
public:
    // Default constructor
    // es el constructor base
    DoubleCell();
    // Constructor with value
    // crea la clase con un valor ingresado
    explicit DoubleCell(double value);
    // Copy constructor
    // crea la clase y la copia de otro double cell
    DoubleCell(const DoubleCell& other);
    //Reference constructor
    // crea y mueve el valor de otro double cell
    DoubleCell(DoubleCell &&rhs) noexcept;
    // Destructor
    // elimina tu Double cell
    ~DoubleCell() = default;
    // en los siguientes tres te enseña a que debes hacer con un igual al asignar
    // Assignment operator by copy
    DoubleCell &operator=(const DoubleCell &rhs);
    // Assignment operator by reference
    DoubleCell &operator=(DoubleCell&& other) noexcept ;
    // Assignment operator for double
    DoubleCell& operator=(double value);

    // Arithmetic operators
    // aqui le dices que hacer con los signos aritmeticos
    DoubleCell operator +(const DoubleCell& other) const;
    DoubleCell operator +(const double other) const;
    DoubleCell operator -(const DoubleCell& other) const;
    DoubleCell operator -(const double other) const;
    DoubleCell operator *(const DoubleCell& other) const;
    DoubleCell operator *(const double other) const;
    DoubleCell operator /(const DoubleCell& other) const;
    DoubleCell operator /(const double other) const;

    //sirven para ponerle valor a la variable y para ver el valor en la variable
    // Setters
    void SetValue(double newValue);
    // Getters
    [[nodiscard]] double GetValue() const;


private:
    // valor guardado
    double Storedvalue;
};

#endif  // DOUBLE_CELL_H
