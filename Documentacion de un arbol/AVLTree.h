#ifndef AVL_TREE_H
#define AVL_TREE_H
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<memory>
//Plantilla de nodo
template <typename T>
// clase nodo
class Node {
    // datos publicos
public:
    // dato guardado
    T data;
    // donde se encuentra el nodo
    int height;
    // punto al hijo izquierdo
    std::shared_ptr<Node<T>> left;
    // puntero al derecho
    std::shared_ptr<Node<T>> right;
    // constructor
    Node(T data) : data(data), height(1), left(nullptr), right(nullptr) {}
};

// plantilla del arbol
template <typename T>
// clase principal
class AVLTree {
    // atributos publicos
public:
    //puntero a raiz
    std::shared_ptr<Node<T>> root;
    // constructor
    AVLTree(): root(nullptr) {}
    //agregar nodo
    void add(T data) {
        root = insert(root, data);
    }
    // eliminar nodo
    void remove(T data)  {
        root = deleteNode(root, data);
    }
    // imprimir
    void print() {
        if (root != nullptr) {
            print(root, 0);
        } else {
            std::cout << "The tree is empty." << std::endl;
        }
    }

private:
    // funcion para imprimir, es recursiva
    void print(std::shared_ptr<Node<T>> node, int indent) {
        if(node) {
            if(node->right) {
                print(node->right, indent + 8);
            }
            if (indent) {
                std::cout << std::setw(indent) << ' ';
            }
            if (node->right) {
                std::cout << " / (Right of " << node->data << ")\n" << std::setw(indent) << ' ';
            }
            std::cout << node->data << "\n" ;
            if (node->left) {
                std::cout << std::setw(indent) << ' ' << " \\ (Left of " << node->data << ")\n";
                print(node->left, indent + 8);
            }
        }
    }
    // funcion para crear un nodo
    std::shared_ptr<Node<T>> newNode(T data) {
        return std::make_shared<Node<T>>(data);
    }
    // rotacion derecha
    // guarda un nodo derecho como x y uno izquierdo como y
    // actualiza el tamaño de ambas
    std::shared_ptr<Node<T>> rightRotate(std::shared_ptr<Node<T>> y)
    {
        std::shared_ptr<Node<T>> x = y->left;
        std::shared_ptr<Node<T>> T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right))+1;
        x->height = max(height(x->left), height(x->right))+1;
        return x;
    }
    // rotacion izquierda
    // guarda el nodo x como y, y el y como t2
    // actualiza el tamaño de ambas
    std::shared_ptr<Node<T>> leftRotate(std::shared_ptr<Node<T>> x)
    {
        std::shared_ptr<Node<T>> y = x->right;
        std::shared_ptr<Node<T>> T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left),height(x->right))+1;
        y->height = max(height(y->left),height(y->right))+1;
        return y;
    }
    // equilibra el nodo
    int getBalance(std::shared_ptr<Node<T>> N) {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }
    // funcion para insertar
    std::shared_ptr<Node<T>> insert(std::shared_ptr<Node<T>> node, T data) {
        if (node == nullptr)
            return (newNode(data));

        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node;
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        if (balance > 1 && data < node->left->data)
            return rightRotate(node);
        if (balance < -1 && data > node->right->data)
            return leftRotate(node);
        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
// busca el nodo con el valor mas chico
    std::shared_ptr<Node<T>> minValueNode(std::shared_ptr<Node<T>> node) {
        std::shared_ptr<Node<T>> current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }
// elimna el nodo
    std::shared_ptr<Node<T>> deleteNode(std::shared_ptr<Node<T>> root, T data) {
        if (!root)
            return root;

        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        }
        else if(data > root->data) {
            root->right = deleteNode(root->right, data);
        }
        else {
            if(!root->left || !root->right) {
                root = (root->left) ? root->left : root->right;
            }
            else {
                std::shared_ptr<Node<T>> temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
                temp.reset();
            }
        }

        if(!root)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }
// te da el tamaño del nodo, si no existe da 0
    int height(std::shared_ptr<Node<T>> N) {
        if (N == nullptr)
            return 0;
        return N->height;
    }
// funcion para comparar, regresa el valor mas grande
    int max(int a, int b) {
        return (a > b)? a : b;
    }
};

#endif /* AVL_TREE_H */
