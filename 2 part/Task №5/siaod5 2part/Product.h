#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H

struct Product {
	char name[20] = "";
	char manufacturer[20] = "";
	char country[20] = "";
	int price = 0;
	int code = 0;
};
static int PRODUCT_SIZE = sizeof(Product);
void printRecord(Product product);
#endif // !1