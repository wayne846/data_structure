#include <stdlib.h>

template <class T>
class Queue{
    private:
        class Node{
            public:
                T data;
                Node *next;
                Node(T a){
                    this->data = a;
                    this->next = NULL;
                }
        };

        Node *root;
        int mysize;
    
    public:
        Queue();
        ~Queue();
        void push(T x);
        T pop();
        T front();
        void clear();
        int size();
};

template <class T>
Queue<T>::Queue(){
    root = NULL;
    mysize = 0;
}

template <class T>
Queue<T>::~Queue(){
    clear();
}

template <class T>
void Queue<T>::push(T x){
    Node *newNode = new Node(x);
    if(root == NULL){
        root = newNode;
        mysize++;
        return;
    }
    Node *current = root;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    mysize++;
}

template <class T>
T Queue<T>::pop(){
    Node *deleteNode = root;
    T value = root->data;
    root = root->next;
    delete(deleteNode);
    deleteNode = NULL;
    return value;
}

template <class T>
T Queue<T>::front(){
    return root->data;
}

template <class T>
void Queue<T>::clear(){
    Node *current = root;
    while(current != NULL){
        Node *deleteNode = current;
        current = current->next;
        delete(deleteNode);
        deleteNode = NULL;
    }
    mysize = 0;
    root = NULL;
}

template <class T>
int Queue<T>::size(){
    return mysize;
}