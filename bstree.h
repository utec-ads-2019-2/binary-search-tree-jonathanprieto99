#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    Node<T> *root;

    public:
        BSTree() : root(nullptr) {};
        int nodes;

/*
        Node<T>* minValueNode(Node<T>* nodo)
        {
            auto NodeActual = nodo;
            while(NodeActual and NodeActual->left != nullptr)
                NodeActual = NodeActual->left;
            return NodeActual;
        }
        */

        bool find(T data) {
            Node<T>*temporal=this->root;

            if (temporal == nullptr){
                return false;
            }

            if (temporal->data == data){
                    return true;
            }

            if (root){
                find2(data,temporal);
            }

        }

        bool find2(T data,Node<T>*&temporal2){//Profe puso Node<T>*&temporal2

            if (temporal2 == nullptr){
                return false;
            }

            if (temporal2->data==data){
                return true;
            }

            if (temporal2->data<data){
                temporal2=temporal2->right;
                find2(data,temporal2);
            }

            if (temporal2->data > data){
                temporal2=temporal2->left;
                find2(data,temporal2);
            }
        }

        void insert(T data) {

            auto*temporal= new Node<T>;
            temporal->data=data;
            temporal->right= nullptr;
            temporal->left= nullptr;

            Node<T>*recorredor=root;
            Node<T>*recorredor2;

            if(root== nullptr){
                root=temporal;
            }

            while (recorredor != nullptr) {
                recorredor2 = recorredor;
                if (data < recorredor->data)
                    recorredor = recorredor->left;
                else
                    recorredor = recorredor->right;
            }

            if(data<recorredor2->data){
                recorredor2->left=temporal;
        }
            else{
                recorredor2->right=temporal;
            }
            nodes++;
        }

        bool remove(T data) {
            Node<T> *recorredor = root;
            if (root = nullptr) {
                return true;
            }
            if (data < recorredor->data) {
                recorredor = recorredor->right;
                remove(data);
            } else if (data > recorredor->data) {
                recorredor = recorredor->left;
                remove(data);
            } else {
                if (root->left == nullptr) {
                    Node<T> *temporal = root->right;
                    delete (root);
                } else if (root->right == nullptr) {
                    Node<T> *temporal = root->left;
                    delete (root);
                }
                return true;
            }
        }

        unsigned int size() {
            return this->nodes;
        }

        void traversePreOrder() {
            // TODO
        }

        void traverseInOrder() {
            // TODO
        }

        void traversePostOrder() {
            // TODO
        }

        Iterator<T> begin() {
            // TODO
        }

        Iterator<T> end() { 
            // TODO
        }

        ~BSTree() {
            // TODO
        }
};

#endif
