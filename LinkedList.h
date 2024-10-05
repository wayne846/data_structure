template <class T>
class LinkedList{
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
        LinkedList();
        ~LinkedList();
        void push_front(T x);
        void push_back(T x);
        void erase(T x);
        void clear();
        int size();

        T& operator[](int index);
};

template <class T>
LinkedList<T>::LinkedList(){
    root = nullptr;
    mysize = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
    clear();
}

template <class T>
void LinkedList<T>::push_front(T x){
    Node *newNode = new Node(x);
    newNode->next = root;
    root = newNode;
    mysize++;
}

template <class T>
void LinkedList<T>::push_back(T x){
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
void LinkedList<T>::erase(T x){
    Node *current = root;
    Node *previous = nullptr;
    while(current != nullptr && current->data != x){
        previous = current;
        current = current->next;
    }
    if(current == nullptr){
        return;
    }else if(current == root){
        root = current->next;
        delete(current);
        current = nullptr;
        mysize--;
    }else{
        previous->next = current->next;
        delete(current);
        current = nullptr;
        mysize--;
    }
}

template <class T>
void LinkedList<T>::clear(){
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
int LinkedList<T>::size(){
    return mysize;
}

template <class T>
T& LinkedList<T>::operator[](int index){
    Node *current = root;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    return current->data;
}