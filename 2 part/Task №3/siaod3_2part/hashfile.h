#pragma once
#ifndef HASHFILE_H
#define HASHFILE_H
#include "Product.h"
#include "hashtable.h"
#include "binfile.h"
#include <string>
using namespace std;

void InsertBinHash(HashTable& hashTable, string bin_file_name, int number = -1);
void DeleteByKeyHash(HashTable& hashTable, string bin_file_name, int key);
void GetByKeyHash(HashTable& hashTable, string bin_file_name, int key);

#endif // !1
