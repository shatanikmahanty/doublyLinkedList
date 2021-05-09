#include <iostream>
#include "DoublyLinkedList.cpp"

using namespace std;

template<typename T>
class queue {
    DoublyLinkedList<T> list;

public:
    void enqueue(T *data);

    void dequeue();

    void display() {
        list.forwardTraversal();
    }
};

template<typename T>
void queue<T>::enqueue(T *data) {
    list.insertNodeAtEnd(data);
}

template<typename T>
void queue<T>::dequeue() {
    list.deleteAtFront();
}

int main() {

    queue<int> q;

    int ch;

    do {
        cout << "\nPress 1 to enqueue.\n";
        cout << "Press 2 to dequeue.\n";
        cout << "Press 3 to display.\n";
        cout << "Press 0 to exit.\n";

        cout << "\nChoose your Option : \n";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter a value";
                int value;
                cin >> value;
                q.enqueue(&value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
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

