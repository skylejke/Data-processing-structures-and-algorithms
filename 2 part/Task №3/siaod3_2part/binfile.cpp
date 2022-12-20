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
        cout << "Файла с таким именем не существует" << endl;
    }
    fin.close();
}

bool CheckIndex(string bin_file_name, int index) {
    ifstream fin;
    fin.open(bin_file_name, ios::binary | ios::in);
    Product temp;
    int count = 0;
    while (fin.read((char*)&temp, sizeof(Product))) {
        count++;
    }
    fin.close();
    if (count > index) {
        return true;
    }
    else {
        return false;
    }
}

Product GetRecordFromBin(string bin_file_name, int index) {
    ifstream fin;
    fin.open(bin_file_name, ios::binary | ios::in);
    Product result{};

    if (fin.is_open()) {
        if (!CheckIndex(bin_file_name, index)) return result;
        Product dict;
        fin.seekg(index * sizeof(Product), ios::beg);
        fin.read((char*)&dict, sizeof(Product));
        result = dict;
    }
    return result;
    fin.close();
}

void AddRecordToBin(string bin_file_name, Product product) {
    fstream fout;
    fout.open(bin_file_name, ios::binary | ios::in | ios::out);
    if (fout.is_open()) {
        fout.seekg(0, ios::end);
        fout.write((char*)&product, sizeof(Product));
    }
    else {
        cout << "Файла с таким именем не существует" << endl;
    }
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
        cout << "Файла с таким именем не существует" << endl;
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

bool DeleteByKey(string bin_file_name, int key) {
    ifstream bitFile(bin_file_name, ios::binary | ios::in);
    if (!bitFile.is_open()) {
        cout << "Файла с таким именем не существует" << endl;
    }

    ofstream tempFile("temp.bin", ios::out | ios::binary);
    if (!tempFile.is_open()) {
        bitFile.close();
        cout << "Файла с таким именем не существует" << endl;
    }

    bitFile.seekg(0, ios::end);
    int size = bitFile.tellg();
    bitFile.seekg(0, ios::beg);

    string s;
    Product product;
    while (bitFile.read((char*)&product, sizeof(product))) {
        if (product.code == key) {
            continue;
        }
        tempFile.write((char*)&product, sizeof(product));
    }

    bitFile.close();
    tempFile.close();

    remove(bin_file_name.c_str());
    if (rename("temp.bin", bin_file_name.c_str()) == 0) {
        return true;
    }
    else {
        return false;
    }

}

void testBinF() {
    cout << "Создание файла..." << endl;
    string bin_file_name = "test.bin";
    ConvertTextToBin(bin_file_name, "file.txt");
    OutputBinFile(bin_file_name);
    cout << "-----------------------" << endl;

    cout << "Добавление записи..." << endl;
    Product product = { "orange", "orange_factory", "egypt", 1, 343434 };
    AddRecordToBin(bin_file_name, product);
    OutputBinFile(bin_file_name);
    cout << "-----------------------" << endl;

    cout << "Удаление записи..." << endl;
    DeleteByKey(bin_file_name, 343434);
    OutputBinFile(bin_file_name);
    cout << "-----------------------" << endl;

    cout << "Прямой доступ к 0 записи..." << endl;
    printRecord(DirectAccess(bin_file_name, 0));
    cout << "-----------------------" << endl;
}
