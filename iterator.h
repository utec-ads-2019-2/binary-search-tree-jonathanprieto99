#ifndef ITERATOR_H
#define ITERATOR_H
#include <stack>
#include <iostream>
#include "node.h"

using namespace std;
template <typename T> 

class Iterator {

    private:

        Node<T> *current;
        stack<Node<T>*>* stack1;
        stack<Node<T>*>* stack2;

    public:

        Iterator() {

            current = nullptr;
            stack1 = new stack<Node<T>*>;
            stack2 = new stack<Node<T>*>;

        }

    explicit Iterator(Node<T> *node) {
            if(!node) {
                current = nullptr;
                stack1 = new stack<Node<T>*>;
                stack2 = new stack<Node<T>*>;
            }
            else{
                stack1 = new stack<Node<T>*>;
                stack2 = new stack<Node<T>*>;

                current = node;
                while(current->left)
                {
                    stack1->push(current);
                    current = current->left;
                }
            }
        }

        Iterator<T>& operator=(const Iterator<T> &other) {

            current = other.current;
            *stack1 = other.stack1;
            *stack2 = other.stack2;
            // Falta return
        }

        bool operator!=(Iterator<T> other) {

            return &current!= &other.current;

        }

        Iterator<T>& operator++() {

            if(current==nullptr){

                return *this;

            }

            stack2->push(current);

            if(current->right) {

                current = current->right;

                while(current->left)

                {
                    stack1->push(current);
                    current = current->left;

                }
            }

            else {

                if(stack1->size()>0) {

                    current = stack1->top();
                    stack1->pop();

                }

                else{
                    current = nullptr;
                }

            }

            return *this;
        }

        Iterator<T>& operator--() {
            if(stack2->empty()){
                return *this;
            }

            if(current==nullptr) {
                current=stack2->top();
                stack2->pop();
            }
            else {
                stack1->push(current);
                current = stack2->top();
                stack2->pop();
            }

            return *this;
        }

        T operator*() {
            if(current==nullptr){
                throw ( "Current = nullptr" ); ;
            }
            return current->data;
        }
};

#endif
