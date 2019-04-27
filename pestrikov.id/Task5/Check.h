#pragma once
#include "Array.h"
#include "Product.h"

class Check
{
public:
	
	void addProduct(Product product);
	std::string getDescription();

	int getTotalCost() { return mTotalCost; }
	int getTotalDiscount() { return mTotalDiscount; }
	int calculateFinalTotalCost() {
		return mTotalCost - mTotalDiscount;
	}

private:
	Array<Product> mProducts;
	Array<int> mProductCounts;

	int mTotalCost = 0;
	int mTotalDiscount = 0;
	
	std::string getProductDescription(const Product& product, int count);	
};






