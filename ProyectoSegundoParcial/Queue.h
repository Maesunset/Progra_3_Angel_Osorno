#ifndef PROYECTO_SEGUNDO_PARCIAL_QUEUE_H
#define PROYECTO_SEGUNDO_PARCIAL_QUEUE_H

template<typename ZL>
class Queue : private DLList<ZL> {
public:
    // constructores
    Queue()
    {
        DLList<ZL>::init();
    }
    void enqueue(ZL &data) {
        DLList<ZL>::push_back(data);
    }
    void enqueue(ZL &&data) {
        DLList<ZL>::push_back(data);
    }
    // destructor
    ~Queue() {
        clear();
        delete DLList<ZL>::head;
        delete DLList<ZL>::tail;
    }
    // Elimina el primer dato en la cola
    void dequeue() {
        DLList<ZL>::pop_front();
    }

    // Imprime la cola
    void print()
    {
        DLList<ZL>::print();
    }
    // elimina la cola
    void clear()
    {
        DLList<ZL>::clear();
    }
    // muestra el primer elemto de la cola
    ZL front()
    {
        return DLList<ZL>::head->next->data;
    }
};

#endif //PROYECTO_SEGUNDO_PARCIAL_QUEUE_H