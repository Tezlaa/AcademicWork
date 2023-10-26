#include <iostream>

class Node {
public:
    int data;
    int priority;
    Node* next;
    Node* prev;

    Node(int data, int priority) : data(data), priority(priority), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList {
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int data, int priority) {
        Node* newNode = new Node(data, priority);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void remove(Node* node) {
        if (node == nullptr) return;

        if (node == head) {
            head = head->next;
        }

        if (node == tail) {
            tail = tail->prev;
        }

        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }

        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }

        delete node;
    }

    Node* getHighestPriorityNode() const {
        Node* current = head;
        Node* highestPriorityNode = head;

        while (current != nullptr) {
            if (current->priority < highestPriorityNode->priority) {
                highestPriorityNode = current;
            }
            current = current->next;
        }

        return highestPriorityNode;
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "Data: " << current->data << " Priority: " << current->priority << std::endl;
            current = current->next;
        }
    }

private:
    Node* head;
    Node* tail;
};

class PriorityQueue {
public:
    PriorityQueue() : list() {}

    void enqueue(int data, int priority) {
        list.append(data, priority);
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
        }
        else {
            Node* highestPriorityNode = list.getHighestPriorityNode();
            list.remove(highestPriorityNode);
        }
    }

    bool isEmpty() const {
        return list.isEmpty();
    }

    void display() const {
        list.display();
    }

private:
    DoubleLinkedList list;
};

int main() {
    PriorityQueue queue;

    queue.enqueue(10, 2);
    queue.enqueue(20, 1);
    queue.enqueue(30, 3);
    queue.enqueue(40, 2);

    std::cout << "Queue elements:" << std::endl;
    queue.display();

    while (!queue.isEmpty()) {
        std::cout << "Dequeue: ";
        queue.dequeue();
        queue.display();
    }

    return 0;
}
