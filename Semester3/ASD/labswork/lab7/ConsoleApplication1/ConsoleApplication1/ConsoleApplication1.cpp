#include <iostream>
#include <fstream>
#include <chrono>
#include <string> 
#include <vector>
#include "bstree.h"
#include "hashtable.h"

using namespace std;


// EXP 1
//int main() {
//    const char* filename = "war_and_peace.txt.utf8";
//
//    BinarySearchTree bstree;
//    ifstream file(filename);
//    char word[256];
//    vector<string> words_in_bstree;
//    int n = 0;
//
//    while (file >> word && n < 200000) {
//        n++;
//        int value = rand();
//        bstree.insert(word, value);
//        words_in_bstree.push_back(word);
//
//        if (n % 10000 == 0) {
//            int randomPosition = rand() % words_in_bstree.size();
//            string randomElement = words_in_bstree[randomPosition];
//            const char* charRandomElement = randomElement.data();
//
//            auto start_time = chrono::high_resolution_clock::now();
//            bstree.lookup(charRandomElement);
//            auto end_time = chrono::high_resolution_clock::now();
//            const auto durationNS = (end_time - start_time).count();
//
//            chrono::duration<double, milli> fp_ms = end_time - start_time;
//            const auto durationMS = fp_ms.count();
//
//            cout << n << " " << durationMS << " milli" << endl;
//        }
//    }
//    words_in_bstree.clear();
//    cout << endl << endl;
//
//    HashTable hashtable(200000);
//    vector<string> words_in_hashtable;
//    file.clear();
//    file.seekg(0);
//
//    n = 0;
//    while (file >> word && n < 200000) {
//        n++;
//        int value = rand();
//        hashtable.insert(word, value);
//        words_in_hashtable.push_back(word);
//
//        if (n % 10000 == 0) {
//            int randomPosition = rand() % words_in_hashtable.size();
//            string randomElement = words_in_hashtable[randomPosition];
//            const char* charRandomElement = randomElement.data();
//
//            auto start_time = chrono::high_resolution_clock::now();
//            hashtable.lookup(charRandomElement);
//            auto end_time = chrono::high_resolution_clock::now();
//            const auto durationNS = (end_time - start_time).count();
//
//            chrono::duration<double, milli> fp_ms = end_time - start_time;
//            const auto durationMS = fp_ms.count();
//
//            cout << n << " " << durationMS << " milli" << endl;
//        }
//    }
//    words_in_hashtable.clear();
//
//    return 0;
//}

 //EXP 3
int main() {
    BinarySearchTree bstree;
    string word;
    char _char = 'a';
    int n_char = 0;
    int n = 0;

    while (n < 200000) {
        n++;
        int value = rand();

        word = string(n_char, _char + (n % 100));
        if (n % 26 == 0) {
            n_char ++;
        }

        bstree.insert(word.data(), value);

        if (n % 50000 == 0) {
            _char++;
            auto start_time = chrono::high_resolution_clock::now();
            bstree.lookup(word.data());
            auto end_time = chrono::high_resolution_clock::now();
            const auto durationNS = (end_time - start_time).count();

            chrono::duration<double, milli> fp_ms = end_time - start_time;
            const auto durationMS = fp_ms.count();

            cout << n << " " << durationMS << " milli" << endl;
        }
        word = "";
    }

    cout << endl << endl;

    HashTable hashtable(200000);

    n = 0;
    while (n < 200000) {
        n++;
        int value = rand();

        word = string(n_char, _char + (n % 100));
        if (n % 26 == 0) {
            n_char++;
        }

        hashtable.insert(word.data(), value);

        if (n % 50000 == 0) {
            _char++;
            auto start_time = chrono::high_resolution_clock::now();
            hashtable.lookup(word.data());
            auto end_time = chrono::high_resolution_clock::now();
            const auto durationNS = (end_time - start_time).count();

            chrono::duration<double, milli> fp_ms = end_time - start_time;
            const auto durationMS = fp_ms.count();

            cout << n << " " << durationMS << " milli" << endl;
        }
        word = "";
    }

    return 0;
}

// EXP 6

int main() {
    int n = 0;
    string word;
    int n_char = 0;
    char _char = 'a';
    vector<string> words_in_hashtable;

    HashTable hashtable(200000, "Y");

    while (n < 200000) {
        n++;
        int value = rand();

        word = string(n_char, _char + (n % 100));
        if (n % 26 == 0) {
            n_char++;
        }

        words_in_hashtable.push_back(word);

        hashtable.insert(word.data(), value);

        if (n % 20000 == 0) {
            int randomPosition = rand() % words_in_hashtable.size();
            string randomElement = words_in_hashtable[randomPosition];
            const char* charRandomElement = randomElement.data();

            auto start_time = chrono::high_resolution_clock::now();
            if (hashtable.lookup(charRandomElement) == -1) {
                cout << "not found" << endl;
            }
            auto end_time = chrono::high_resolution_clock::now();
            const auto durationNS = (end_time - start_time).count();

            chrono::duration<double, milli> fp_ms = end_time - start_time;
            const auto durationMS = fp_ms.count();

            cout << n << " " << durationMS << " milli" << " " << hashtable.collisions << endl;
        }
        word = "";
    }

    return 0;
}