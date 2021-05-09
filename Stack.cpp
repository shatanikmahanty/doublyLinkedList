#include <iostream>
#include "DoublyLinkedList.cpp"

using namespace std;

template<typename T>
class stack {
    DoublyLinkedList<T> list;

public:
    void push(T *data);

    void pop();

    void display() {
        list.forwardTraversal();
    }
};

template<typename T>
void stack<T>::push(T *data) {
    list.insertNodeAtFront(data);
}

template<typename T>
void stack<T>::pop() {
    list.deleteAtFront();
}

int main() {

    stack<int> stk;
    int value;
    int ch;

    do {
        cout << "\nPress 1 to push.\n";
        cout << "Press 2 to pop.\n";
        cout << "Press 3 to display.\n";
        cout << "Press 0 to exit.\n";

        cout << "\nChoose your Option : \n";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter a value";
                cin >> value;
                stk.push(&value);
                break;
            case 2:
                stk.pop();
                break;
            case 3:
                stk.display();
                break;
            case 0:
                cout << "Exiting.....";
                exit(0);
            default:
                cout << "Invalid Choice. Try Again";
                continue;
        }
    } while (true);
}

