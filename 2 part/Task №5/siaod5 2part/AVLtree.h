#pragma once
#include "Product.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class AVLtree {
private:
    struct Node {
        Product value;
        int key = -1;
        int index = -1;

        Node* left = nullptr;
        Node* right = nullptr;
        int height = -1;
    };
    int size = -1;
   
    
    int height(Node* node);
    int height_diff(Node* node);
    void fixheight(Node* node);
    Node* rotateright(Node* p);
    Node* rotateleft(Node* q);
    Node* balance(Node* node);
    Node* findMinNode(Node* node);
    Node* removeMinNode(Node* node);
    void print(Node* node, string space);

public:
    Node* head = nullptr;
    int rotations = 0;

    bool createAVLTree(string bin_file_name);
    Node* addNode(Node* p, Product pr, int index);
    Node* removeNode(Node* p, int k);
    int findNode(int k);
    void printTree();
};

