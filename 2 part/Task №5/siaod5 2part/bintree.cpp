#include "bintree.h"

BinaryTree::BinaryTree() {
    head = new Node();
}

bool BinaryTree::createTree(string bin_file_name) {
    ifstream fin;
    fin.open(bin_file_name, ios::binary | ios::in);
    Product product;
    if (fin.is_open()) {
        int index = 0;
        while (fin.read((char*)&product, PRODUCT_SIZE)) {
            addNode(product, index);
            index++;
        }
        fin.close();
        return true;
    }
    return false;
}

void BinaryTree::addNode(Product product, int index) {
    Node* temp = head;
    while (true) {
        if (temp->value.code==0) {
            temp->value = product;
            temp->key = product.code;
            temp->index = index;
            break;
        }
        else if (temp->value.code < product.code) {
            if (temp->right == nullptr) {
                temp->right = new Node;
            }
            temp = temp->right;
        }
        else if (temp->value.code > product.code) {
            if (temp->left == nullptr) {
                temp->left = new Node;
            }
            temp = temp->left;
        }
    }
}

int BinaryTree::findNode(int key) {
    Node* temp = head;
    while (true) {
        if (temp == nullptr) {
            return -1;
        }
        else if (temp->value.code == key) {
            return temp->index;
        }
        else if (temp->value.code < key) {
            temp = temp->right;
        }
        else if (temp->value.code > key) {
            temp = temp->left;
        }
    }
    return -1;
}

BinaryTree::Node* BinaryTree::findMinNode(Node* node, Node* parent, int left) {
    if (node->left == nullptr) {
        parent->left = nullptr;
        return node;
    }
    return findMinNode(node->left, node, true);
}

bool BinaryTree::removeNode(int key) {
    Node* temp = head;
    Node* parent = head;
    int flag = 0;
    if (findNode(key) == -1) {
        return false;
    }
    while (true) {
        if (temp->value.code == key) {
            if (flag) parent->right = nullptr;
            else parent->left = nullptr;

            if (temp->left == nullptr && temp->right == nullptr) {
                delete temp;
            }
            else if (temp->left == nullptr) {
                parent->right = temp->right;
                delete temp;
            }
            else if (temp->right == nullptr) {
                parent->left = temp->left;
                delete temp;
            }
            else {
                Node* res = findMinNode(temp->right, temp, true);
                res->left = temp->left;
                res->right = temp->right;
                delete temp;
                if (flag) parent->right = res;
                else parent->left = res;
            }
            return true;
        }
        else if (temp->value.code < key) {
            flag = 1;
            parent = temp;
            temp = temp->right;
        }
        else {
            flag = 0;
            parent = temp;
            temp = temp->left;
        }
    }
    return false;
}

void BinaryTree::print(Node* node, string space) {
    if (node->right != nullptr) {
        print(node->right, space + "    ");
    }
    cout << space << node->value.name << " " << node->value.code << " " << node->value.manufacturer << " " << node->value.price << " " << node->value.country << "(" << node->index << ")" << endl;
    if (node->left != nullptr) {
        print(node->left, space + "    ");
    }
}

void BinaryTree::printTree() {
    print(head, "");
}