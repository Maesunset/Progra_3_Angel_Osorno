#ifndef TEMA_1_FLOATCELL_H
#define TEMA_1_FLOATCELL_H

// class
class FloatCell{
public:
    // constructor default (implicito)
    // es cuando creas la variable sin darle un valor definido
    explicit FloatCell(float newValue = 0);
    // explicit copia solo entra cuando se asigna un r valor
    FloatCell(const FloatCell &rhs);
    // explicito referencia solo entra cuando se asigna un l valor
    FloatCell(FloatCell &&rhs) noexcept;
    // destructor se activa cuando se usa "free"
    ~FloatCell() = default;

    FloatCell &operator=(const FloatCell &rhs);
    FloatCell &operator=(FloatCell &&rhs)noexcept;

    //esto solo funciona cuando trabaja con si mismo
    FloatCell &operator = (float rhs);
    //operaciones logicas
    FloatCell &operator + (const FloatCell &rhs);

    //FloatCell &operator - (const FloatCell &rhs);


    // funciones geters, se usa para ver que valor esta asignado
    [[nodiscard]] float getValue() const;
    // funciones setters, se usa para darle un valor
    void SetValue(float newValue);

private:
    float storeValue;
};
#endif