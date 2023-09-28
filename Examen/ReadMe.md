# Parte 1.1

i. ¿Qué es un Rvalor y un Lvalor?
R. Un L valor es el dato que va del lado izquierdo del igual pero también puede ir del lado derecho
en cambio un R valor va del lado derecho pero no siempre puede ir del lado Izquierdo.
ii. ¿Porqué es necesario que una clase tenga constructores y operadores por
copia y por referencia?
R.  Para guardar cualquier tipo de dato que le pases mientras corresponda al dato guardado, es decir te pueden pasar una variable, una constante y una clase.
iii. ¿Qué función desarrollan los :: en la implementación de la clase?
R. :: que solo lo modifica solo la misma clase  : que accede a ese espacio en especifico
iv. ¿Cómo se le denomina a cuando una clase posee un operador puede
tener múltiples implementaciones dependiendo de los argumentos que
este reciba?
R. sobre carga.
v. ¿Cúal es la funcion del archivo .h ?
R. es un archivo de cabecera y sirve como una librería externa.
# parte 2
Calcular la complejidad temporal en Big(O) Notación del siguiente algoritmo:

````
#include <iostream>
int algoritmo1(int n) 
{
	int resultado = 0;
	for (int i = 0; i < n; i++) 
	{
		resultado += i; // Operación simple O(1)
	}
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			resultado += i * j; // Operación simple O(1)
		}
	}
	return resultado;
}

int main() 
{
int n;
std::cout << "Ingrese el valor de n: ";
	std::cin >> n;
Parte 2
Complejidad Temporal
int resultado = algoritmo1(n);
std::cout << "Resultado: " << resultado << std::endl;
return 0;
}
````
Al solo tener 2 for´s anidados su complejidad analizada es de $n^2$ 
