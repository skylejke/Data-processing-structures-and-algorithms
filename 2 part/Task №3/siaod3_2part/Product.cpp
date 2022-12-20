#include "Product.h"
#include <iostream>
using namespace std;

void printRecord(Product product) {
    cout << product.name << " " << product.code << " " << product.manufacturer << " " << product.price << " " << product.country << endl;
}
