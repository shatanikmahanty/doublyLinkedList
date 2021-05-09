#include<iostream>
#include "Node.cpp"

using namespace std;

template<typename T>
class DoublyLinkedList {
    Node<T> *head, *tail;
public :
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    void insertNodeAtFront(T *);

    void forwardTraversal();

    void backwardTraversal();

    void insertNodeAtEnd(T *);

    void insertBeforeANode(T *, T *); //Homework
    void insertAfterANode(T *, T *);  //homework
    void deleteAtFront();

    void deleteAtEnd();

    void deleteANode(T *); //homework
    void reverseTheList();

    int searchInList(T *); //Return position of searched item. Returns -1 if not found
};

template<typename T>
void DoublyLinkedList<T>::insertNodeAtFront(T *data) {
    Node<T> *n = nullptr;
    n = n->createNode(data);
    if (head == nullptr) {
        head = tail = n;
        return;
    }
    n->setNextNode(head);
    head->setPreviousNode(n);
    head = n;
}

template<typename T>
void DoublyLinkedList<T>::forwardTraversal() {
    if (head == nullptr) {
        cout << "empty list!";
        return;
    }
    Node<T> *start = head;
    while (start) {
        T data = *start->getData();
        cout << "==>" << data;
        start = start->getNextNode();
    }
    cout << endl;
}


template<typename T>
void DoublyLinkedList<T>::backwardTraversal() {
    if (head == nullptr) {
        cout << "empty list!";
        return;
    }
    Node<T> *start = tail;
    while (start) {
        T data = *start->getData();
        cout << "==>" << data;
        start = start->getPreviousNode();
    }
    cout << endl;
}

template<typename T>
void DoublyLinkedList<T>::insertNodeAtEnd(T *data) {
    Node<T> *n = nullptr;
    n = n->createNode(data);
    if (head == nullptr) {
        head = tail = n;
        return;
    }
    n->setPreviousNode(tail);
    tail->setNextNode(n);
    tail = n;
}

template<typename T>
void DoublyLinkedList<T>::deleteANode(T *data) {
    if (head == nullptr) {
        cout << "\nList is empty!" << endl;
        return;
    }

    int res = searchInList(data);
    if (res == -1) {
        cout << "Node not found for given data. Delete failed";
    } else {
        Node<T> *current = head;
        for (int i = 1; current != nullptr && i < res; i++)
            current = current->getNextNode();

        /* 'res' is greater than the number of nodes in the doubly linked list */
        if (current == nullptr)
            return;

        if (head == current)
            head = current->getNextNode();

        if (current->getNextNode() != nullptr)
            current->getNextNode()->setPreviousNode(current->getPreviousNode());


        if (current->getPreviousNode() != nullptr)
            current->getPreviousNode()->setNextNode(current->getNextNode());

        cout << "\nDeleted Node : " << (*current->getData()) << endl;
        delete current;
    }

}

template<typename T>
void DoublyLinkedList<T>::deleteAtFront() {
    if (head == nullptr) {
        cout << "\nList is empty!" << endl;
        return;
    }
    Node<T> *temp = head;
    if (head == tail) {
        head = tail = nullptr;    //Case for single node.
    } else {                      //More than one node.
        head = head->getNextNode();
        head->setPreviousNode(nullptr);
        temp->setNextNode(nullptr);
    }
    cout << "\nDeleted Node : " << (*temp->getData()) << endl;
    delete temp;
}

template<typename T>
void DoublyLinkedList<T>::deleteAtEnd() {
    if (head == nullptr) {
        cout << "\nList is empty!" << endl;
        return;
    }
    Node<T> *temp = tail;
    if (head == tail) {  //Single node case
        head = tail = nullptr;
    } else {  //Multiple node case
        tail = tail->getPreviousNode();
        tail->setNextNode(nullptr);
        temp->setPreviousNode(nullptr);
    }
    cout << "\nDeleted Node : " << (*temp->getData()) << endl;
    delete temp;
}


template<typename T>
void DoublyLinkedList<T>::insertAfterANode(T *beforeNodeData, T *data) {
    if (head == nullptr) {
        cout << "\nList is empty!" << endl;
        return;
    }

    int res = searchInList(beforeNodeData);
    if (res == -1) {
        cout << "\nNode with the given data does not exist. Insert failed\n";
        return;
    } else {
        Node<T> *prevNode = head;
        for (int i = 1; prevNode != nullptr && i < res; i++)
            prevNode = prevNode->getNextNode();

        Node<T> *newNode = nullptr;
        newNode = newNode->createNode(data);

        newNode->setNextNode(prevNode->getNextNode());

        prevNode->setNextNode(newNode);

        newNode->setPreviousNode(prevNode);

        if (newNode->getNextNode() != nullptr)
            newNode->getNextNode()->setPreviousNode(newNode);
    }
}

template<typename T>
void DoublyLinkedList<T>::insertBeforeANode(T *afterNodeData, T *data) {
    if (head == nullptr) {
        cout << "\nList is empty!" << endl;
        return;
    }


    int res = searchInList(afterNodeData);
    if (res == -1) {
        cout << "\nNode with the given data does not exist. Insert failed\n";
        return;
    } else {
        Node<T> *afterNode = head;
        for (int i = 1; afterNode != nullptr && i < res; i++)
            afterNode = afterNode->getNextNode();

        Node<T> *newNode = nullptr;
        newNode = newNode->createNode(data);

        newNode->setPreviousNode(afterNode->getPreviousNode());

        afterNode->setPreviousNode(newNode);

        newNode->setNextNode(afterNode);

        if (newNode->getPreviousNode() != nullptr)
            newNode->getPreviousNode()->setNextNode(newNode);

        else
            head = newNode;

    }
}

template<typename T>
void DoublyLinkedList<T>::reverseTheList() {
    Node<T> *temp = nullptr;
    Node<T> *current = head;

    while (current != nullptr) {
        temp = current->getPreviousNode();
        current->setPreviousNode(current->getNextNode());
        current->setNextNode(temp);
        current = current->getPreviousNode();
    }

    if (temp != nullptr)
        head = temp->getPreviousNode();
}

template<typename T>
int DoublyLinkedList<T>::searchInList(T *data) {

    Node<T> *temp = head;

    int pos = 0;

    while (*temp->getData() != *data
           && temp->getNextNode() != nullptr) {

        pos++;

        temp = temp->getNextNode();
    }

    if (*temp->getData() != *data)
        return -1;

    return (pos + 1);
}


//int main() {
//    DoublyLinkedList<int> dl;
//    int A[] = {10, 20, 30, 40};
//    dl.insertNodeAtFront(&A[0]);
//    dl.insertNodeAtFront(&A[1]);
//    dl.insertNodeAtFront(&A[2]);
//    dl.insertNodeAtFront(&A[3]);
//    cout << "Forward Traversal" << endl;
//    dl.forwardTraversal();
//    int B[] = {90, 80, 70, 60, 50};
//    dl.insertNodeAtEnd(&B[0]);
//    dl.insertNodeAtEnd(&B[1]);
//    dl.insertNodeAtEnd(&B[2]);
//    dl.insertNodeAtEnd(&B[3]);
//    dl.insertNodeAtEnd(&B[4]);
//    cout << "Backward Traversal" << endl;
//    dl.backwardTraversal();
//    dl.deleteAtEnd();
//    dl.deleteAtEnd();
//    dl.forwardTraversal();
//    dl.deleteAtFront();
//    dl.deleteAtFront();
//    dl.forwardTraversal();
//    dl.reverseTheList();
//    dl.forwardTraversal();
//    int s = 70, s2 = 20;
//    cout << "\n" << "Found at position : " << dl.searchInList(&s) << "\n";
//    dl.deleteANode(&s);
//    dl.forwardTraversal();
//    dl.deleteANode(&s2);
//    dl.forwardTraversal();
//    int beforeData = 90, data = 20, afterData = 70;
//    dl.insertAfterANode(&beforeData, &data);
//    dl.insertBeforeANode(&beforeData, &data);
//    dl.forwardTraversal();
//    return 0;
//}
