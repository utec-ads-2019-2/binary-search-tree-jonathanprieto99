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

        bool find(T data) { 
            if (root== nullptr or root->data==data){
                    return root;
            }
            if (root->data < data){
                    root=root->right;
                    return find(data);
            }
            if (root->data > data){
                    root=root->left;
                    return find(data);
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
                this->root=temporal;
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
            Node<T>*recorredor=root;
            if(root= nullptr){
                return true;
            }
            if(data<recorredor->data){
                recorredor=recorredor->right;
                remove(data);
            }
            else if(data>recorredor->data){
                recorredor=recorredor->left;
                remove(data);
            }
        }

        unsigned int size() {
            return this->nodes;
        }

        size_t height() {
            // TODO
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
