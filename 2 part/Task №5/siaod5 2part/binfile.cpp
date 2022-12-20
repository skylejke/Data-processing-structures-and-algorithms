#include "binfile.h"

void ConvertTextToBin(string bin_file_name, string txt_file_name) {
    ifstream fin(txt_file_name, ios::in);
    if (fin.is_open()) {
        ofstream fout(bin_file_name, ios::out | ios::binary);
        Product product;
        while (!fin.eof()) {
            fin >> product.name >> product.code >> product.manufacturer >> product.price >> product.country;
            fout.write((char*)&product, sizeof(Product));
        }
        fout.close();
    }
    else {
        cout << "File not found" << endl;
    }
    fin.close();
}

void OutputBinFile(string bin_file_name) {
    ifstream fin(bin_file_name, ios::in | ios::binary);
    Product product;
    if (fin.is_open()) {
        while (fin.read((char*)&product, sizeof(Product))) {
            cout << product.name << " " << product.code << " " << product.manufacturer << " " << product.price << " " << product.country << "\n";
        }
    }
    else {
        cout << "File not found" << endl;
    }
    fin.close();
}

Product DirectAccess(string bin_file_name, int number) {

    ifstream binFile(bin_file_name, ios::binary | std::ios::in);
    if (!binFile.is_open()) {
        cout << "Файла с таким именем не существует" << endl;
    }

    binFile.seekg(0, ios::end);
    long long size = binFile.tellg();

    binFile.seekg(0, std::ios::beg);
    if ((PRODUCT_SIZE * sizeof(char)) * number > size) {
        binFile.close();
        return {};
    }

    binFile.seekg((PRODUCT_SIZE)*number);

    Product product;
    binFile.read((char*)&product, sizeof(product));

    binFile.close();
    return product;
}
