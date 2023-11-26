#include "bstree.h"
#include <cstring>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() { }

void BinarySearchTree::insert(const char* key, int value) {
    insert(root, key, value);
}

void BinarySearchTree::insert(TreeNode*& node, const char* key, int value) {
    if (node == nullptr) {
        node = new TreeNode(key, value);
        return;
    }

    int compareResult = strcmp(key, node->key);
    if (compareResult < 0) {
        insert(node->left, key, value);
    }
    else if (compareResult > 0) {
        insert(node->right, key, value);
    }
    else {
        node->value = value;
    }
}

int BinarySearchTree::lookup(const char* key) {
    return lookup(root, key);
}

int BinarySearchTree::lookup(TreeNode* node, const char* key) {
    if (node == nullptr) {
        return -1;
    }

    int compareResult = strcmp(key, node->key);
    if (compareResult < 0) {
        return lookup(node->left, key);
    }
    else if (compareResult > 0) {
        return lookup(node->right, key);
    }
    else {
        return node->value;
    }
}
