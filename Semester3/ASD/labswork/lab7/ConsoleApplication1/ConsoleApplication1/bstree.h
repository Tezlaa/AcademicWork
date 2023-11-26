#ifndef BSTREE_H
#define BSTREE_H
#include <cstring>

struct TreeNode {
    char key[256];
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const char* k, int v) : value(v), left(nullptr), right(nullptr) {
        strncpy_s(key, sizeof(key), k, sizeof(key) - 1);
    }
};

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(const char* key, int value);
    int lookup(const char* key);

private:
    TreeNode* root;

    void insert(TreeNode*& node, const char* key, int value);
    int lookup(TreeNode* node, const char* key);
};

#endif
