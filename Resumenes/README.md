una clase se separa en 2 archivos el .h y el .cpp.
en el .h se pone por así decirlo el esqueleto de la clase, lo que es y para lo que sirve en este caso tiene 3 constructores uno explicito y 2 implícitos.
luego tiene un destructor.
después le enseñas a usar el signo igual y Como aceptar valores tipo int.
tiene los setter y getters.
al final tiene el valor guardado.
````
#ifndef TEMA_1_FLOATCELL_H  
#define TEMA_1_FLOATCELL_H  
  
// class  
class FloatCell{  
public:  
    // constructor default (implicito)  
    // es cuando creas la variable sin darle un valor definido    explicit FloatCell(float newValue = 0);  
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
 
    // funciones geters, se usa para ver que valor esta asignado    [[nodiscard]] float getValue() const;  
    // funciones setters, se usa para darle un valor  
    void SetValue(float newValue);  
  
private:  
    float storeValue;  
};  
#endif
````
La segunda parte del codigo esta en un archivo .cpp y le dices a la clase como hacer todo lo que le pides en el .h.
lo primero que te muestra son los 3 constructores, el explicito o default, el por copia y por movimiento.
luego te muestra los operadores por asignación.
y por ultimo los getter y setters que con para obtener y mostrar el valor guardado
````
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
````
así se vería el uso en un main:
````
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
````
este código mostraría lo siguiente en consola: