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

            Node<T> *temporal= new Node<T>(data);

            Node<T>*recorredor=root;

            if(root==nullptr){
                root=temporal;
		return;
            }

            while (recorredor != nullptr) {
                	if (data < recorredor->data){
			if(recorredor->left){
                    	recorredor = recorredor->left;
			}
			else recorredor->left=temporal;
                }
                else{
			if(recorredor->right) recorredor = recorredor->left;
                        else recorredor->right=temporal;
                }
            }
            nodes++;
        }

    Node<T>* minValueNode(Node<T>* node)
    {
        auto currentNode = node;
        while(currentNode && currentNode->left)
            currentNode = currentNode->left;
        return currentNode;
    }

    bool remove(T data) {
            Node<T> *recorredor = root;
            Node<T> *recorredor2;

            if (!find(data)) return false;

            if (data < recorredor->data) {
                recorredor2=recorredor;
                recorredor = recorredor->right;
                remove(data);
            }

            else if (data > recorredor->data) {
                recorredor2=recorredor;
                recorredor = recorredor->left;
                remove(data);
            }

            else {

                if (recorredor->left == nullptr and recorredor->right == nullptr) {
                    delete (recorredor);
                }

                else if (recorredor->left && !recorredor->right) {
                    recorredor2->left=recorredor->left;
                    delete(recorredor);
                }
                else if(recorredor->right && !recorredor->left){
                    recorredor2->right=recorredor->right;
                    delete(recorredor);
                }

                else if (recorredor->right!=nullptr and recorredor->left!=nullptr) {
                    Node<T> *temporal;
                    temporal=minValueNode(recorredor->right);
                    if(temporal!= nullptr){

                    }
                }

                //Test
                }
                Node<T> *temporal = minValueNode(root->right);
                root->data = temporal->data;
                root->right = remove(root->right, temporal->data);

                return true;
            }

        unsigned int size() {
            return this->nodes;
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
