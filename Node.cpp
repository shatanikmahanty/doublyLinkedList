#include <iostream>
using namespace std;

template <typename T>
class Node{
    Node *previous, *next;
    T *data;
public:
    Node *createNode(T *data);
    Node *getPreviousNode();
    Node *getNextNode();
    void setPreviousNode(Node *);
    void setNextNode(Node *);
    T *getData();
};
template <typename T>
Node<T> * Node<T>::createNode(T *dataP){
    Node *n = new Node();
    n->data = dataP;
    n->previous=n->next=nullptr;
    return n;
}
template <typename T>
Node<T> * Node<T>::getPreviousNode(){
    return previous;
}
template <typename T>
Node<T> * Node<T>::getNextNode(){
    return next;
}
template <typename T>
T * Node<T>::getData(){
    return data;
}
template <typename T>
void Node<T>::setPreviousNode(Node *n){
    this->previous = n;
}
template <typename T>
void Node<T>::setNextNode(Node *n){
    this->next = n;
}
