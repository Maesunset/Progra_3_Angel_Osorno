#ifndef INTCELL_H
#define INTCELL_H

class IntCell {
public:
    // explicit constructor, solo sirve para r valores
    explicit IntCell(int newValue = 0);
    // constructores por copia y movimiento sirve para l valores
    IntCell(const IntCell &rhs);
    IntCell(IntCell &&rhs) noexcept;
    //destructor
    ~IntCell() = default;

    // aqui le enseñas a usar el valor de igual
    IntCell &operator=(const IntCell &rhs);
    IntCell &operator=(IntCell &&rhs) noexcept;

    //operador de asignación para aceptar ints primitivos
    IntCell &operator=(int rhs);

    // asignar y mostrar el valor guardado
    int getValue(int i) const;
    void setValue(int newValue);

private:
    // valor guardado
    int storedValue;
};
#endif  // INTCELL_H
