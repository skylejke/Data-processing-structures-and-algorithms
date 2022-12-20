#include <vector>
#include <string>
#include <iostream>
using namespace std;

void KMP_stage1(string subline, vector<int>& pi) {
    pi[0] = 0;
    int i = 1, j = 0;
    for (; i < subline.size();) {
        if (subline[i] == subline[j]) {
            pi[i] = j + 1;
            i++;
            j++;
        }
        else if (j == 0) {
            pi[i] = 0;
            i++;
        }
        else {
            j = pi[j - 1];
        }
    }
}

int KMP_stage2(string line, string subline, vector<int> pi) {
    if (line == "") {
        return -1;
    }
    int i = 0, j = 0;
    for (;;) {
        if (line[i] == subline[j]) {
            j++;
            i++;
            if (j == subline.size() - 1) return i - 1;
        }
        else {
            if (j == 0) {
                i++;
                if (i >= line.size() - 1) return -1;
            }
            else {
                j = pi[j - 1];
            }
        }
    }
}

int CountInput(string line, string subline) {
    vector<int> pi;
    pi.resize(subline.size());
    KMP_stage1(subline, pi);
    int count = 0;
    int indexInput = 0;
    indexInput = KMP_stage2(line.substr(indexInput), subline, pi);
    while (indexInput != -1 && indexInput + subline.size() <= line.size()) {
        count++;
        indexInput = KMP_stage2(line.substr(indexInput + subline.size()), subline, pi) + subline.size() + indexInput;
    }
    return count;
}

int main() {
    system("chcp 1251 > null");
    string text;
    string subline;
    cout << "Введите строку: ";
    getline(cin, text);
    cout << "Введите подстроку: ";
    getline(cin, subline);
    cout << "Количество вхождений подстроки в строку: " << CountInput(text, subline) << endl;
    return 0;
}