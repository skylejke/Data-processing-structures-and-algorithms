#include "hashfile.h"

void InsertBinHash(HashTable& hashTable, string bin_file_name, int number) {
    fstream bitFile(bin_file_name, ios::binary | ios::in | ios::app);
    if (!bitFile.is_open()) {
        cout << "Error opening file";
        return;
    }
    int cnt = 0;
    if (number == -1) {
        while (!bitFile.eof()) {
            Product product;
            bitFile.read((char*)&product, sizeof(Product));
            hashTable.add(product.code, cnt);
            cnt++;
        }
    }
    else {
        int temp;
        temp = DirectAccess(bin_file_name, number).code;
        hashTable.add(temp, number);
    }
}

void DeleteByKeyHash(HashTable& hashTable, string bin_file_name, int key) {
    int number = hashTable.get(key);
    if (number == -1) {
        cout << "Îøèáêà" << endl;
        return;
    }
    hashTable.remove(key);
    DeleteByKey(bin_file_name, key);
}

void GetByKeyHash(HashTable& hashTable, string bin_file_name, int key) {
    int number = hashTable.get(key);
    if (number == -1) {
        cout << "Îøèáêà" << endl;
        return;
    }
    printRecord(DirectAccess(bin_file_name, number));
}
