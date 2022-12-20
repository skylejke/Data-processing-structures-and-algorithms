#pragma once
#include "Product.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class BinaryTree {
private:
    struct Node {
        Product value;
        int key = -1;
        int index = -1;

        Node* left = nullptr;
        Node* right = nullptr;
    };
    Node* head;
    void print(Node* node, string space = "");
    Node* findMinNode(Node* node, Node* parent, int left);

public:
    BinaryTree();
    bool createTree(string bin_file_name);
    void addNode(Product product, int index);
    int findNode(int key);
    bool removeNode(int key);
    void printTree();
};

