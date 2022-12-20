#ifndef BINFILE_H
#define BINFILE_H
#include "Product.h"
#include <fstream>
#include <iostream>
using namespace std;
void ConvertTextToBin(string bin_file_name, string txt_file_name);
bool CheckIndex(string bin_file_name, int index);
Product GetRecordFromBin(string path, int index);
void AddRecordToBin(string path, Product product);
void OutputBinFile(string bin_file_name);
bool DeleteByKey(string bin_file_name, int key);
Product DirectAccess(string bin_file_name, int number);
void testBinF();
#endif
