#include <iostream>
#include <cstdlib>
#include <stack>
#ifndef PROYECTO_SEGUNDO_PARCIAL_STACK_H
#define PROYECTO_SEGUNDO_PARCIAL_STACK_H

template <typename ZL>
        class Stack : private DLList<ZL> {
        public:
            // constructores
            Stack()
            {
                DLList<ZL>::init();
            }
            void push(ZL &data)
            {
                DLList<ZL>::push_front(data);
            }
            void push(ZL &&data)
            {
                DLList<ZL>::push_front(data);
            }
            // destructor
            ~Stack()
            {
                clear();
                delete DLList<ZL>::head;
                delete DLList<ZL>::tail;
            }
            // Eliminar el dato de hasta adelante
            void pop()
            {
                DLList<ZL>::pop_front();
            }
            // Limpia la stack
            void clear()
            {
                DLList<ZL>::clear();
            }
            // imprime el stack
            void print()
            {
                DLList<ZL>::print();
            }
            // muestra el primer dato
            ZL top()
            {
                return DLList<ZL>::head->next->data;
            }
        };

#endif //PROYECTO_SEGUNDO_PARCIAL_STACK_H
