#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T val;
    Node* next;

    Node(const T& val) : val(val), next(nullptr) {}
};

template <typename T>
class StackLinkedList {
private:
    Node<T>* head;
    int count;

public:
    StackLinkedList() : head(nullptr), count(0) {}

    ~StackLinkedList() {
        clear();
    }

    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    T top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }
        return head->val;
    }

    void add(const T& val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
        count++;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }
        Node<T>* temp = head;
        T value = temp->val;
        head = temp->next;
        delete temp;
        count--;
        return value;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    StackLinkedList<T> copy() {
        StackLinkedList<T> newStack;
        Node<T>* curNode = head;
        while (curNode != nullptr) {
            newStack.add(curNode->val);
            curNode = curNode->next;
        }
        return newStack;
    }

    StackLinkedList<T> operator+(const StackLinkedList<T>& other) {
        StackLinkedList<T> newStack;
        Node<T>* curNode1 = head;
        Node<T>* curNode2 = other.head;
        while (curNode1 != nullptr && curNode2 != nullptr) {
            if (curNode1->val < curNode2->val) {
                newStack.add(curNode1->val);
                curNode1 = curNode1->next;
            }
            else {
                newStack.add(curNode2->val);
                curNode2 = curNode2->next;
            }
        }
        while (curNode1 != nullptr) {
            newStack.add(curNode1->val);
            curNode1 = curNode1->next;
        }
        while (curNode2 != nullptr) {
            newStack.add(curNode2->val);
            curNode2 = curNode2->next;
        }
        return newStack;
    }

    StackLinkedList<T> operator*(const StackLinkedList<T>& other) {
        StackLinkedList<T> newStack;

        Node<T>* curNode1 = this->head;
        Node<T>* curNode2 = other.head;

        while (curNode1 != nullptr) {
            while (curNode2 != nullptr) {
                if (curNode1->val == curNode2->val) {
                    newStack.add(curNode1->val);
                    break;
                }
                curNode2 = curNode2->next;
            }
            curNode2 = other.head;
            curNode1 = curNode1->next;
        }

        return newStack;
    }
};


int main() {
    StackLinkedList<int> intStack1;
    intStack1.add(1);
    intStack1.add(3);
    intStack1.add(5);

    StackLinkedList<int> intStack2;
    intStack2.add(2);
    intStack2.add(4);
    intStack2.add(6);

    StackLinkedList<int> intStack3 = intStack1 + intStack2;

    cout << "Merged stack: " << endl;
    while (!intStack3.isEmpty()) {
        cout << intStack3.pop() << " ";
    }
    cout << endl;

    StackLinkedList<double> doubleStack1;
    doubleStack1.add(1.2);
    doubleStack1.add(1.4);
    doubleStack1.add(7.2);

    StackLinkedList<double> doubleStack2;
    doubleStack2.add(1.2);
    doubleStack2.add(1.4);
    doubleStack2.add(1.1);
    doubleStack2.add(5.2);

    StackLinkedList<double> doubleStack3 = doubleStack2 * doubleStack1;

    cout << "Intersection stack: " << endl;
    while (!doubleStack3.isEmpty()) {
        cout << doubleStack3.pop() << " ";
    }
    cout << endl;

    StackLinkedList<double> doubleStack4 = doubleStack1.copy();

    cout << "Copied stack: " << endl;
    while (!doubleStack4.isEmpty()) {
        cout << doubleStack4.pop() << " ";
    }
    cout << endl;

    return 0;
}
