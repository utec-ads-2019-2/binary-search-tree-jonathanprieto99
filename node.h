#ifndef NODE_H
#define NODE_H

template <typename T>
class BSTree; 

template <typename T>
class Iterator; 

template <typename T>
class Node {
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(): data(0) {left = right = nullptr;}
    Node(T data) : data(data){ left = right = nullptr; }

    template<class>
    friend class BSTree; 

    template<class>
    friend class Iterator; 
};

#endif