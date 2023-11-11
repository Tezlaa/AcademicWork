//#include <iostream>
//
//using namespace std;
//
//
//template <typename T>
//class Node {
//public:
//    T data;
//    Node* left;
//    Node* right;
//
//    Node(T value) : data(value), left(nullptr), right(nullptr) {}
//};
//
//
//template <typename T>
//class BinaryTree {
//private:
//    Node<T>* root;
//
//    Node<T>* insert(Node<T>* node, T value) {
//        if (node == nullptr) {
//            return new Node<T>(value);
//        }
//
//        if (value < node->data) {
//            node->left = insert(node->left, value);
//        }
//        else if (value > node->data) {
//            node->right = insert(node->right, value);
//        }
//
//        return node;
//    }
//
//    void inorder(Node<T>* node) {
//        if (node == nullptr) {
//            return;
//        }
//        inorder(node->left);
//        cout << node->data << " ";
//        inorder(node->right);
//    }
//
//public:
//    BinaryTree() : root(nullptr) {}
//
//    void insert(T value) {
//        root = insert(root, value);
//    }
//
//    void inorder() {
//        inorder(root);
//    }
//
//};
//
//
//int main()
//{
//    BinaryTree<int> tree;
//
//    tree.insert(50);
//    tree.insert(30);
//    tree.insert(70);
//    tree.insert(20);
//    tree.insert(40);
//    tree.insert(60);
//    tree.insert(80);
//
//    std::cout << "In-order: ";
//    tree.inorder();
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct TrafficViolation {
    string violationType;
    string date;
    double fineAmount;
};


struct TreeNode {
    string licensePlate;
    vector<TrafficViolation> violations;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const string& plate) : licensePlate(plate), left(nullptr), right(nullptr) {}
};


class TrafficDatabase {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, const string& plate, const TrafficViolation& violation) {
        if (node == nullptr) {
            node = new TreeNode(plate);
            node->violations.push_back(violation);
        }
        else if (plate < node->licensePlate) {
            node->left = insert(node->left, plate, violation);
        }
        else if (plate > node->licensePlate) {
            node->right = insert(node->right, plate, violation);
        }
        else {
            node->violations.push_back(violation);
        }

        return node;
    }

    void printDatabase(TreeNode* node) const {
        if (node == nullptr) {
            return;
        }
        printDatabase(node->left);

        cout << "\nLicense Plate: " << node->licensePlate << endl;
        for (const auto& violation : node->violations) {
            cout << "  Violation: " << violation.violationType
                << ", Date: " << violation.date
                << ", Fine: " << violation.fineAmount << endl;
        }

        printDatabase(node->right);
    }

    TreeNode* searchByLicensePlate(TreeNode* node, const string& plate) const {
        if (node == nullptr || node->licensePlate == plate) {
            return node;
        }

        if (plate < node->licensePlate) {
            return searchByLicensePlate(node->left, plate);
        }

        return searchByLicensePlate(node->right, plate);
    }

public:
    TrafficDatabase() : root(nullptr) {}

    void addViolation(const string& plate, const TrafficViolation& violation) {
        root = insert(root, plate, violation);
    }

    void printDatabase() const {
        printDatabase(root);
    }

    void printByLicensePlate(const string& plate) const {
        TreeNode* result = searchByLicensePlate(root, plate);
        if (result != nullptr) {
            cout << "\nDatabase for License Plate " << plate << ":" << endl;
            for (const auto& violation : result->violations) {
                cout << "  Violation: " << violation.violationType
                    << ", Date: " << violation.date
                    << ", Fine: " << violation.fineAmount << endl;
            }
        }
        else {
            cout << "No data found for License Plate " << plate << endl;
        }
    }
};

int main() {
    TrafficDatabase database;

    TrafficViolation violation1 = { "Speeding", "2023-01-01", 100.0 };
    TrafficViolation violation2 = { "Parking", "2023-02-01", 50.0 };

    database.addViolation("ABC123", violation1);
    database.addViolation("XYZ789", violation2);
    database.addViolation("ABC123", violation2);

    database.printDatabase();

    database.printByLicensePlate("ABC123");

    return 0;
}
