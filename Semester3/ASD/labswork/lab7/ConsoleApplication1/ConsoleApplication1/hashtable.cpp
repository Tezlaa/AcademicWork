#include "hashtable.h"
#include <cstring>
#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;


HashTable::HashTable(int size, string name_hash_func) : size(size), name_hash_func(name_hash_func){
    values = new int[size];
    keys = new char* [size];
    for (int i = 0; i < size; ++i) {
        keys[i] = nullptr;
    }
}

HashTable::~HashTable() {
    delete[] values;
    for (int i = 0; i < size; ++i) {
        delete[] keys[i];
    }
    delete[] keys;
}

void HashTable::insert(const char* key, int value) {
    int index = get_index(key);

    collisions = 0;

    while (keys[index] != nullptr) {
        if (strcmp(keys[index], key) == 0) {
            values[index] = value;
            return;
        }
        index = (index + 1) % size;
        collisions++;
    }

    keys[index] = new char[strlen(key) + 1];
    if (keys[index] == nullptr) {
        return;
    }
    strcpy_s(keys[index], strlen(key) + 1, key);
    values[index] = value;
}

int HashTable::lookup(const char* key) {
    int index = get_index(key);

    while (keys[index] != nullptr) {
        if (strcmp(keys[index], key) == 0) {
            return values[index];
        }
        index = (index + 1) % size;
    }

    return -1;
}

int HashTable::hash(const char* key) {
    int hashValue = 0;
    for (int i = 0; key[i] != '\0'; ++i) {
        hashValue = (hashValue * 31 + key[i]) % size;
    }
    return (hashValue < 0) ? -hashValue : hashValue;
}

int HashTable::hashY(const char* key) {
    static const unsigned int FNV_PRIME = 16777619u;
    static const unsigned int OFFSET_BASIS = 2166136261u;
    const size_t length = strlen(key) + 1;
    unsigned int hash = OFFSET_BASIS;
    for (size_t i = 0; i < length; ++i)
    {
        hash ^= *key++;
        hash *= FNV_PRIME;
    }
    return hash % size;
}

int HashTable::get_index(const char* key) {
    int index;
    if (name_hash_func == "Y") {
        index = hashY(key);
    }
    else {
        index = hash(key);
    }
    return index;
}