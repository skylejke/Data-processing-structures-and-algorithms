#include "BinaryTree.h"

int inputElement(int& number) {
    while (1) {
        cout << "Введите элемент дерева: ";
        if ((cin >> number).good() && (number > 0)) {
            return number;
        }
        if (cin.fail()) {
            cin.clear();
            cout << endl << "Неверный ввод, повторите." << endl << endl;
        }
        else {
            cout << endl << "Число вне допустимого диапазона значений. Повторите ввод." << endl << endl;
        }
        cin.ignore(100, '\n');
    }
}

point* BuildTree(int n, point* p){
    point* r;
    int nl, nr;
    if (n == 0) { 
        p = nullptr; 
        return p; 
    }
    nl = n / 2;
    nr = n - nl - 1;
    r = new point;
    inputElement(r->data);
    r->left = BuildTree(nl, r->left);
    r->right = BuildTree(nr, r->right);
    p = r;
    return p;
}

void PrintTree(point* p, int level) {
    if (p) {
        PrintTree(p->right, level + 1);
        for (int i = 0; i < level; i++) {
            cout << "   ";
        }
        cout << p->data << endl;
        PrintTree(p->left, level + 1);
    }
}

int TreeHeight(point* p) {
    if (!p) {
        return 0;
    }
    int h_l = TreeHeight(p->left);
    int h_r = TreeHeight(p->right);
    return max(h_l, h_r) + 1;
}

void breadthFirst(point* p) {
    int max_data = INT_MIN;
    list <point*> q;
    q.push_back(p);
    while (!q.empty()) {
        point* tmp = (point*)q.front();
        q.pop_front();
        if (tmp->left) {
            q.push_back(tmp->left);
        }
        if (tmp->right) {
            q.push_back(tmp->right);
        }
        if (tmp->data > max_data) {
            max_data = tmp->data;
        }
    }
    cout << "Максимальное значение = " << max_data << endl;
}

int MaxValue(point* p) {
    int max_data = INT_MIN;
    if (!p) {
        return 0;
    }
    if (p->data > max_data) {
        max_data = p->data;
    }

    while (p->right != nullptr) {
        p = p->right;
        if (p->data > max_data) {
            max_data = p->data;
        }
    }

    while (p->left != nullptr) {
        p = p->left;
        if (p->data > max_data) {
            max_data = p->data;
        }
    }

    return max_data;
}

int MinValue(point* p){
    int min_data = INT_MAX;
    if (!p) {
        return 0;
    }
    if (p->data < min_data) {
        min_data = p->data;
    }

    while (p->right != nullptr) {
        p = p->right;
        if (p->data < min_data) {
            min_data = p->data;
        }
    }

    while (p->left != nullptr) {
        p = p->left;
        if (p->data < min_data) {
            min_data = p->data;
        }
    }

    return min_data;
}

void DeleteTree(point*& p) {
    if (p) {
        DeleteTree(p->left);
        DeleteTree(p->right);
        delete p;
        p = nullptr;
    }
}