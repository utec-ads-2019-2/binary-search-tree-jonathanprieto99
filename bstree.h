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
        int nodes{};

        bool find(T data) {

            Node<T> *temporal = root;

            if (!temporal)
            {
                return false;
            }

            if (root!=nullptr){

                find2(data,temporal);
                return true;
            }
            else{
                return false;
            }
            return false;

        }

        bool find2(T data,Node<T> *&temporal){//Profe puso Node<T>*&temporal
            if (temporal)
            {
                if (temporal->data==data){
                    return true;
                }else if (temporal->data>data){
                    temporal=temporal->left;
                    find2(data,temporal);
                }else {
                    temporal=temporal->right;
                    find2(data,temporal);
                }
            }else{
                return false;
            }
            return true;
        }

        bool insert(T data) {

            Node<T> *recorredor = root, *recorredor2;
            if(!root){
                root = new Node<T>(data);
                nodes++;
                return true;
            }
            while (recorredor) {
                recorredor2 = recorredor;
                if (data < recorredor->data){
                    recorredor = recorredor->left;
                }
                else{
                    recorredor = recorredor->right;
                }
            }
            if(data<recorredor2->data){
                recorredor2->left = new Node<T>(data);
            }
            else{
                recorredor2->right = new Node<T>(data);
            }
            nodes++;
            return true;
        }

    Node<T>* minValueNode(Node<T>* node)
    {
        auto currentNode = node;
        while(currentNode && currentNode->left)
            currentNode = currentNode->left;
        return currentNode;
    }

    bool MatadorNodos(Node<T>* tempo,T data) {
            Node<T> *recorredor = root;
            Node<T> *recorredor2;

            if (!find(data)) return false;

            if (data < recorredor->data) {
                recorredor2=recorredor;
                recorredor = recorredor->right;
                MatadorNodos(recorredor,data);
            }

            else if (data > recorredor->data) {
                recorredor2=recorredor;
                recorredor = recorredor->left;
                MatadorNodos(recorredor,data);
            }

            else {

                if (recorredor->left == nullptr and recorredor->right == nullptr) {
                    if (recorredor==root){
                        root=nullptr;
                        delete (recorredor);
                        nodes--;
                        return true;
                    }
                    else{
                        Node<T> *temporal;
                        temporal=minValueNode(recorredor->right);
                        recorredor->data=temporal->data;
                        MatadorNodos(recorredor->right, temporal->data);
                        nodes--;
                        return true;
                    }
                }

                else if (recorredor->left && !recorredor->right) {
                    recorredor2->left=recorredor->left;
                    delete(recorredor);
                    nodes--;
                    return true;
                }
                else if(recorredor->right && !recorredor->left){
                    recorredor2->right=recorredor->right;
                    delete(recorredor);
                    nodes--;
                    return true;
                }

                }
            }

        unsigned int size() {
            return this->nodes;
        }

    bool remove(T data) {
        return MatadorNodos(this->root, data);
    }

        void traversePreOrder(Node<T>* node) {
            if(this->nodes==0){
                return throw;
            }
            else {
                std::cout << node->data << std::endl;
                if(node->left){
                    traversePreOrder(node->left);
                }
                if(node->right){
                    traversePreOrder(node->right);
                }
            }
        }

        void traverseInOrder(Node<T>* node) {
            if(this->nodes==0){
                throw;
            }
            else
            {
                if(node->left){
                    traverseInOrder(node->left);
                }
                std::cout << node->data << std::endl;
                if(node->right){
                    traverseInOrder(node->right);
                }
            };
        }

        void traversePostOrder(Node<T>* node) {
            if(this->nodes==0){
                return throw;
            }
            else
            {
                if(node->left){
                    traversePostOrder(node->left);
                }
                if(node->right){
                    traversePostOrder(node->right);
                }
                std::cout << node->data << std::endl;
            };
        }

        Iterator<T> begin() {
            return Iterator<T> (this->root);
        }

        Iterator<T> end() {
            return Iterator<T> ();
        }

        ~BSTree() {
            this->root->killself(this->root);
        }
};

#endif
