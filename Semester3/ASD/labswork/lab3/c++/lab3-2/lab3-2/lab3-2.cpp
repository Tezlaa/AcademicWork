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
};

int main() {
    StackLinkedList<char> charStack;
    charStack.add('a');
    charStack.add('g');
    charStack.add('y');

    cout << "Stack size: " << charStack.size() << endl;
    while (!charStack.isEmpty()) {
        cout << "Top of the stack: " << charStack.pop() << endl;
    }

    StackLinkedList<string> stringStack;
    stringStack.add("Hello");
    stringStack.add("World");

    cout << "\nStack size: " << stringStack.size() << endl;
    while (!stringStack.isEmpty()) {
        cout << "Top of the stack: " << stringStack.pop() << endl;
    }

    return 0;
}
