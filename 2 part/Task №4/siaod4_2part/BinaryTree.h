#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <list>
using namespace std;
struct point {
    int data = 0;
    point* left = nullptr;
    point* right = nullptr;
};

int inputElement(int& number);
point* BuildTree(int n, point* p);
void PrintTree(point* p, int level);
int TreeHeight(point* p);
void breadthFirst(point* p);
int MaxValue(point* p);
int MinValue(point* p);
void DeleteTree(point*& p);

#endif
