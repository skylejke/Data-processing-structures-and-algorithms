#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Product.h"
#include <iostream>
using namespace std;

struct Node {
    int key;
    int value;
    Node* next;
};

class HashTable {
protected:
    Node** table;
    int currentSize = 0;

public:
    HashTable();
    ~HashTable();
    int hash(int key);
    void add(int key, int value, bool isRehash = false);
    void remove(int key);
    int get(int key);
    void rehash();
    void print();
    int size = 100;
};
void testHeshT();
#endif
