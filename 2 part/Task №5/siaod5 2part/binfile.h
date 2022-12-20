#pragma once
#ifndef BINFILE_H
#define BINFILE_H
#include "Product.h"
#include <fstream>
#include <iostream>
using namespace std;
void ConvertTextToBin(string bin_file_name, string txt_file_name);
void OutputBinFile(string bin_file_name);
Product DirectAccess(string bin_file_name, int number);
#endif
