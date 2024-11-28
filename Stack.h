template <class T>
class Stack{
    private:
        class Node{
            public:
                T data;
                Node *next;
                Node(T a){
                    this->data = a;
                    this->next = nullptr;
                }
        };

        Node *root;
        int mysize;
    
    public:
        Stack();
        ~Stack();
        void push(T x);
        void pop();
        T& top();
        void clear();
        int size();
};

template <class T>
Stack<T>::Stack(){
    root = nullptr;
    mysize = 0;
}

template <class T>
Stack<T>::~Stack(){
    clear();
}

template <class T>
void Stack<T>::push(T x){
    Node *newNode = new Node(x);
    newNode->next = root;
    root = newNode;
    mysize++;
}

template <class T>
void Stack<T>::pop(){
    Node *deleteNode = root;
    root = root->next;
    delete(deleteNode);
    deleteNode = nullptr;
    mysize--;
}

template <class T>
T& Stack<T>::top(){
    return root->data;
}

template <class T>
void Stack<T>::clear(){
    Node *current = root;
    while(current != nullptr){
        Node *deleteNode = current;
        current = current->next;
        delete(deleteNode);
        deleteNode = nullptr;
    }
    mysize = 0;
    root = nullptr;
}

template <class T>
int Stack<T>::size(){
    return mysize;
}