template <class T>
class Queue{
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
        Queue();
        ~Queue();
        void push(T x);
        void pop();
        T& front();
        void clear();
        int size();
};

template <class T>
Queue<T>::Queue(){
    root = nullptr;
    mysize = 0;
}

template <class T>
Queue<T>::~Queue(){
    clear();
}

template <class T>
void Queue<T>::push(T x){
    Node *newNode = new Node(x);
    if(root == nullptr){
        root = newNode;
        mysize++;
        return;
    }
    Node *current = root;
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = newNode;
    mysize++;
}

template <class T>
void Queue<T>::pop(){
    Node *deleteNode = root;
    root = root->next;
    delete(deleteNode);
    deleteNode = nullptr;
    mysize--;
}

template <class T>
T& Queue<T>::front(){
    return root->data;
}

template <class T>
void Queue<T>::clear(){
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
int Queue<T>::size(){
    return mysize;
}