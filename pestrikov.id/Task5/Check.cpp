#include "Check.h"

void Check::addProduct(Product product) {
	mTotalCost += product.getCost();
	mTotalDiscount += product.getCost() / 100 * product.getDiscount();
	for (int i = 0; i < mProducts.getSize(); ++i) {
		if (mProducts[i] == product) {
			++mProductCounts[i];
			return;
		}
	}
	mProducts.pushBack(product);
	mProductCounts.pushBack(1);
}

std::string Check::getProductDescription(const Product& product, int count) {
	std::string result;
	
	result += "Name: ";
	result += product.getName();
	result += " Cost: ";
	result += std::to_string(product.getCost());
	result += " Count: ";
	result += std::to_string(count);
	result += " Total cost: ";
	result += std::to_string(product.getCost() * count);

	return result;
}

std::string Check::getDescription() {
	std::string result;
	for (int i = 0; i < mProducts.getSize(); ++i) {
		result += getProductDescription(mProducts[i], mProductCounts[i]);
		result += "\n";
	}
	result += "Total cost: ";
	result += std::to_string(getTotalCost());
	result += "\nTotal discount: ";
	result += std::to_string(getTotalDiscount());
	result += "\nFinal total cost: ";
	result += std::to_string(calculateFinalTotalCost());
	result += "\n";
	return result;
}