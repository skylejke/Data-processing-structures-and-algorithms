#include "AVLtree.h"

bool AVLtree::createAVLTree(string bin_file_name) {
    ifstream fin;
    fin.open(bin_file_name, ios::binary | ios::in);
    Product product;
    int index = 0;
    if (fin.is_open()) {
        int index = 0;
        while (fin.read((char*)&product, PRODUCT_SIZE)) {
            head = addNode(head, product, index);
            index++;
        }
        fin.close();
        return true;
    }
    return false;
}

int AVLtree::height(Node* node) {
    if (node) {
        return node->height;
    }
    else {
        return 0;
    }
}

int AVLtree::height_diff(Node* node) {
    return height(node->right) - height(node->left);
}

void AVLtree::fixheight(Node* node) {
    int hl = height(node->left);
    int hr = height(node->right);
    if (hl > hr) {
        node->height = hl + 1;
    }
    else {
        node->height = hr + 1;
    }
}

AVLtree::Node* AVLtree::rotateright(Node* p) {
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    rotations++;
    return q;
}

AVLtree::Node* AVLtree::rotateleft(Node* q) {
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    rotations++;
    return p;
}

AVLtree::Node* AVLtree::balance(Node* node) {
    fixheight(node);
    if (height_diff(node) == 2) {
        if (height_diff(node->right) < 0) {
            node->right = rotateright(node->right);
        }
        return rotateleft(node);
    }
    if (height_diff(node) == -2) {
        if (height_diff(node->left) > 0) {
            node->left = rotateleft(node->left);
        }
        return rotateright(node);
    }
    return node;
}

AVLtree::Node* AVLtree::addNode(Node* node, Product product, int index) {
    if (!node) {
        node = new Node;
        node->value = product;
        node->key = product.code;
        node->index = index;
        node->left = node->right = nullptr;
        node->height = 1;
        size++;
        return node;
    }
    if (product.code < node->key) {
        node->left = addNode(node->left, product, index);
    }
    else {
        node->right = addNode(node->right, product, index);
    }
    return balance(node);
}

AVLtree::Node* AVLtree::findMinNode(Node* node) {
    if (node->left) {
        return findMinNode(node->left);
    }
    else {
        return node;
    }
}

AVLtree::Node* AVLtree::removeMinNode(Node* node) {
    if (node->left == 0) {
        return node->right;
    }
    node->left = removeMinNode(node->left);
    return balance(node);
}

AVLtree::Node* AVLtree::removeNode(Node* node, int k) {
    if (!node) {
        return nullptr;
    }
    if (k < node->key) {
        node->left = removeNode(node->left, k);
    }
    else if (k > node->key) {
        node->right = removeNode(node->right, k);
    }
    else {
        Node* q = node->left;
        Node* r = node->right;
        delete node;
        if (!r) {
            return q;
        }
        Node* min = findMinNode(r);
        min->right = removeMinNode(r);
        min->left = q;
        return balance(min);
    }
    return balance(node);
}

int AVLtree::findNode(int k) {
    Node* node = head;
    while (true) {
        if (node == nullptr) {
            return -1;
        }
        if (k < node->key) {
            node = node->left;
        }
        else if (k > node->key) {
            node = node->right;
        }
        else {
            return node->index;

        }
    }
    return -1;
}

void AVLtree::print(Node* node, string space) {
    if (node->right != nullptr) {
        print(node->right, space + "    ");
    }
    cout << space << node->value.name << " " << node->value.code << " " << node->value.manufacturer << " " << node->value.price << " " << node->value.country << " " << node->value.country << "(" << node->index << ")" << endl;
    //cout << space << node->key << " " << node->index << endl;
    if (node->left != nullptr) {
        print(node->left, space + "    ");
    }
}

void AVLtree::printTree() {
    print(head, "");
}



