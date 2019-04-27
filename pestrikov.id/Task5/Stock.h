#pragma once
#include "Array.h"
#include "Product.h"
#include "BarCode.h"

// Склад
class Stock
{
public:

	Stock(){ /* do nothing */ }

	Stock(int size) {
		mProducts.resize(size);
	}

	void addProduct(Product product) {
		mProducts.pushBack(product);
	}

	void addProduct(BarCode barCode, std::string name, int cost, int discount) {
		addProduct(Product(barCode, name, cost, discount));
	}

	Product* getProductByBarCode(BarCode barCode);

private:
	// Все товары, хранящиеся на складе
	Array<Product> mProducts;
};



