#include "hashtable.h"

HashTable::HashTable() {
    this->size = size;
    table = new Node * [size];
    for (int i = 0; i < size; i++) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < size; i++) {
        Node* node = table[i];
        while (node != nullptr) {
            Node* temp = node;
            node = node->next;
            delete temp;
        }
    }
    delete[] table;
}

int HashTable::hash(int key) {
    return key % 17;
}

void HashTable::add(int key, int value, bool isRehash) {
    currentSize++;
    if (currentSize / float(size) > 0.9 or isRehash) {
        rehash();
    }
    int index = hash(key);
    Node* node = table[index];

    table[index] = new Node;
    table[index]->key = key;
    table[index]->value = value;
    table[index]->next = node;

}

void HashTable::remove(int key) {
    int index = hash(key);
    Node* node = table[index];
    Node* prev = nullptr;
    while (node != nullptr) {
        if (node->key == key) {
            if (prev == nullptr) {
                table[index] = node->next;
            }
            else {
                prev->next = node->next;
            }
            delete node;
            return;
        }
        prev = node;
        node = node->next;
    }
}

int HashTable::get(int key) {
    int index = hash(key);
    Node* node = table[index];
    while (node != nullptr) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

void HashTable::rehash() {
    int oldSize = size;
    size *= 2;
    Node** oldTable = table;
    table = new Node * [size];
    for (int i = 0; i < size; i++) {
        table[i] = nullptr;
    }
    for (int i = 0; i < oldSize; i++) {
        Node* node = oldTable[i];
        while (node != nullptr) {
            add(node->key, node->value);
            node = node->next;
        }
    }
    for (int i = 0; i < oldSize; i++) {
        Node* node = oldTable[i];
        while (node != nullptr) {
            Node* temp = node;
            node = node->next;
            delete temp;
        }
    }
    delete[] oldTable;
}

void HashTable::print() {
    for (int i = 0; i < size; i++) {
        Node* node = table[i];
        while (node != nullptr) {
            cout << "[" << i << "]" << " | " << node->key << " " << node->value << endl;
            node = node->next;
        }
    }
}

void testHeshT() {
    cout << "Создание хэш-таблицы..." << endl;
    HashTable hashTable;
    hashTable.add(0, 1);
    hashTable.add(1, 1);
    hashTable.add(1, 2);
    hashTable.add(1, 3);
    hashTable.add(2, 4);
    hashTable.add(3, 5);
    hashTable.print();
    cout << "-----------------------" << endl;

    cout << "Удаление элемента..." << endl;
    hashTable.remove(1);
    hashTable.print();
    cout << "-----------------------" << endl;

    cout << "Получение элемента с ключом 1..." << endl;
    cout << hashTable.get(1) << endl;
    cout << "-----------------------" << endl;

    cout << "Добавление элемента..." << endl;
    hashTable.add(1, 1000);
    hashTable.print();
    cout << "-----------------------" << endl;

    cout << "Тест хэш-функции..." << endl;
    cout << hashTable.hash(1) << endl;
    cout << hashTable.hash(2) << endl;
    cout << "-----------------------" << endl;


    cout << "Рехэширование...." << endl;
    cout << "rehash...\nsize before = " << hashTable.size << endl;
    hashTable.rehash();
    cout << "size after = " << hashTable.size << endl;
    cout << "-----------------------" << endl;

    cout << "Добавление и рехэшивание..." << endl;
    hashTable.add(77, 1, true);
    hashTable.print();
    cout << "after rehash add size = " << hashTable.size << endl;
    cout << "-----------------------" << endl;
}
