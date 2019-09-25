#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"
#include <iostream>
using namespace std;

template <typename T> 
class BSTree {
    Node<T> *root;

    public:
        BSTree() : root(nullptr) {};
        int nodes;

        bool find(T data) {
            Node<T>*temporal=this->root;

            if (temporal == nullptr){
                cout<<data<<" false";
                return false;
            }

            if (temporal->data == data){
                cout<<data<<" true";
                    return true;
            }

            if (root){
                find2(data,temporal);
            }

        }

        bool find2(T data,Node<T>*&temporal2){//Profe puso Node<T>*&temporal2

            if (temporal2 == nullptr){
                cout<<data<<" false";
                return false;
            }

            if (temporal2->data==data){
                cout<<data<<" true";
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

            Node<T> *temporal= new Node<T>;
            temporal->data=data;
            temporal->right= nullptr;
            temporal->left= nullptr;

            Node<T>*recorredor=this->root;
            Node<T>*recorredor2;

            if(root==nullptr){
                root=temporal;
            }

            while (recorredor != nullptr) {
                recorredor2 = recorredor;
                if (data < recorredor->data){
                    recorredor = recorredor->left;
                }
                else{
                    recorredor = recorredor->right;
                }

            }

            if(data<recorredor2->data){
                recorredor2->left=new Node<T>(data);
        }
            else if(data>recorredor2->data){
                recorredor2->right=new Node<T>(data);
            }
            nodes++;
        }

        bool remove(T data) {
            Node<T> *recorredor = root;
            if (root == nullptr) {
                return true;
            }

            if (data < recorredor->data) {
                recorredor = recorredor->right;
                remove(data);
            }

            else if (data > recorredor->data) {
                recorredor = recorredor->left;
                remove(data);
            }

            else {

                if (root->left == nullptr) {
                    Node<T> *temporal = root->right;
                    delete (root);
                }

                else if (root->right == nullptr) {
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
