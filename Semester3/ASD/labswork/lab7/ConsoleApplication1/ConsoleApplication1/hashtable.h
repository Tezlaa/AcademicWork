#include <string>
using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
public:

    HashTable(int size, string name_hash_func = "");
    ~HashTable();

    int collisions = 0;

    void insert(const char* key, int value);
    int lookup(const char* key);

private:
    string name_hash_func;
    char** keys;
    int size;
    int* values;

    int hash(const char* key);
    int hashY(const char* key);
    int get_index(const char* key);
};

#endif
