#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;


template <typename T>
class Node {
public:
    Node* prev;
    Node* next;
    T data;

    Node(T value) : prev(nullptr), next(nullptr), data(value) {}
};

template <typename T>
class DoubleLinkedList {
public:
    Node<T>* head;
    Node<T>* tail;

    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    DoubleLinkedList(const DoubleLinkedList& other) {
        head = nullptr;
        tail = nullptr;
        Node<T>* current = other.head;
        while (current != nullptr) {
            pushBack(current->data);
            current = current->next;
        }
    }

    DoubleLinkedList operator+(const DoubleLinkedList& other) const {
        DoubleLinkedList result(*this);
        Node<T>* current = other.head;
        while (current != nullptr) {
            result.pushBack(current->data);
            current = current->next;
        }
        return result;
    }

    DoubleLinkedList operator*(int n) const {
        DoubleLinkedList result;
        for (int i = 0; i < n; i++) {
            result = result + *this;
        }
        return result;
    }

    void pushBack(int value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void displayList() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " | ";
            current = current->next;
        }
    }
};


class PrintRequest {
public:
    string user;
    time_t timestamp;

    PrintRequest(const string& user) : user(user), timestamp(time(nullptr)) {}

    void displayInfoAboutRequest() {
        cout << user << " | " << timestamp << endl;
    }
};


class PriorityQueue {
private:
    struct Node {
        PrintRequest request;
        int priority;
        Node* prev;
        Node* next;

        Node(const PrintRequest& req, int priority) : request(req), priority(priority), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    PriorityQueue() : head(nullptr), tail(nullptr) {}
    vector<PrintRequest> allRequests;

    void enqueue(const PrintRequest& request, int priority) {
        Node* newNode = new Node(request, priority);

        if (!head || priority > head->priority) {
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next && priority <= current->next->priority) {
                current = current->next;
            }

            newNode->next = current->next;
            if (current->next) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            newNode->prev = current;
        }

        if (!tail) {
            tail = newNode;
        }
        allRequests.push_back(request);
    }

    void dequeue() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
        }
    }

    void displayQueue() {
        Node* current = head;
        while (current) {
            cout << "User: " << current->request.user << " | Priority: " << current->priority << endl;
            current = current->next;
        }
    }

    void printStatistics() {
        cout << "\n\nPrint Queue Statistics:" << endl;
        for (int i = 0; i < allRequests.size(); i++)
        {
            allRequests[i].displayInfoAboutRequest();
        }
        cout << "\nCurrent in the queue:" << endl;
        Node* current = head;
        while (current) {
            cout << "User: " << current->request.user << " | Priority: " << current->priority << " | Time: " << current->request.timestamp << endl;
            current = current->next;
        }
    }
};

int main() {
    PriorityQueue printQueue;

    printQueue.enqueue(PrintRequest("User1"), 2);
    printQueue.enqueue(PrintRequest("User2"), 1);
    printQueue.enqueue(PrintRequest("User3"), 3);

    cout << "Print Queue:" << endl;
    printQueue.displayQueue();

    printQueue.dequeue(); // Dequeue the highest priority request

    cout << "\nPrint Queue after dequeue:" << endl;
    printQueue.displayQueue();

    cout << "\nStatistics:" << endl;
    printQueue.printStatistics();

    return 0;
}

int main() {
    DoubleLinkedList<int> list1, list2, result;
    list1.pushBack(1);
    list1.pushBack(2);
    list2.pushBack(3);
    list2.pushBack(4);

    cout << "First list: ";
    list1.displayList();
    cout << endl;

    cout << "Second list: ";
    list2.displayList();
    cout << endl;

    DoubleLinkedList<int> copiedList = list1;
    cout << "Copy first list: ";
    copiedList.displayList();
    cout << endl;

    result = list1 + list2;

    cout << "Overload '+': ";
    result.displayList();
    cout << endl;

    DoubleLinkedList<int> multipliedList = list1 * 3;

    cout << "Overload '*': ";
    multipliedList.displayList();
    cout << endl;
}
