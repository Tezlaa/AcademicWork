#include <iostream>
#include <fstream>
#include <string>

using namespace std;


template <typename T>
class Node {
public:
    string key;
    T value;
    Node* next;
    Node* prev;

    Node(string k, T v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insert(string key, T value) {
        Node<T>* newNode = new Node<T>(key, value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    bool remove(string key) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                if (current == head) {
                    head = current->next;
                    if (head) head->prev = nullptr;
                }
                else if (current == tail) {
                    tail = current->prev;
                    if (tail) tail->next = nullptr;
                }
                else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                size--;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void insertAtPosition(string key, T value, int position) {
        if (position < 0 || position > size) return;

        Node<T>* newNode = new Node<T>(key, value);
        if (position == 0) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
        }
        else if (position == size) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        else {
            Node<T>* current = head;
            for (int i = 0; i < position - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
        size++;
    }

    bool removeAtPosition(int position) {
        if (position < 0 || position >= size) return false;
        Node<T>* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        if (current == head) {
            head = current->next;
            if (head) head->prev = nullptr;
        }
        else if (current == tail) {
            tail = current->prev;
            if (tail) tail->next = nullptr;
        }
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
        size--;
        return true;
    }

    bool search(string key, T& value) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                value = current->value;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool modify(string key, T newValue) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                current->value = newValue;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->key << " " << current->value << endl;
            current = current->next;
        }
        cout << endl;

    }

    Node<T>* merge(Node<T>* left, Node<T>* right, bool ascending) {
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }

        if ((ascending && left->key < right->key) || (!ascending && left->key > right->key)) {
            left->next = merge(left->next, right, ascending);
            return left;
        }
        else {
            right->next = merge(left, right->next, ascending);
            return right;
        }
    }

    Node<T>* mergeSort(Node<T>* head, bool ascending) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node<T>* middle = head;
        Node<T>* fast = head->next;

        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                middle = middle->next;
                fast = fast->next;
            }
        }

        Node<T>* left = head;
        Node<T>* right = middle->next;
        middle->next = nullptr;

        left = mergeSort(left, ascending);
        right = mergeSort(right, ascending);

        return merge(left, right, ascending);
    }

    void sort(bool ascending) {
        head = mergeSort(head, ascending);
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            Node<T>* current = head;
            while (current != nullptr) {
                file << current->key << " " << current->value << "\n";
                current = current->next;
            }
            file.close();
        }
    }

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList<double> myList;
    ifstream file("data.txt");
    if (file.is_open()) {
        string key;
        double value;
        while (file >> key >> value) {
            myList.insert(key, value);
        }
        file.close();
    }

    myList.display();

    cout << "Search for 'LENOVO': ";
    double lenovoValue;
    if (myList.search("LENOVO", lenovoValue)) {
        cout << "Found. Value: " << lenovoValue << endl;
    }
    else {
        cout << "Not Found." << endl;
    }

    cout << "Modifying 'ASUS' value..." << endl;
    myList.modify("ASUS", 500.0);

    cout << "Removing 'HP'..." << endl;
    myList.remove("HP");

    cout << "Adding 'DELL' with value 32000..." << endl;
    myList.insert("DELL", 32000);

    myList.sort(true);

    myList.display();

    myList.saveToFile("data.txt");

    return 0;
}
