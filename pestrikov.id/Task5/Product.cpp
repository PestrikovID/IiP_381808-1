#include "Product.h"

Product::Product() {
	mBarCode = BarCode::getDefaultBarCodeValue();
	mName = DEFAULT_NAME;
	mCost = MIN_COST;
	mDiscount = MIN_DISCOUNT;
}

Product::Product(BarCode barCode, std::string name, int cost, int discount) {
	if (cost < MIN_COST) {
		std::string exceptionMessage = "Product can't be created because the cost < ";
		exceptionMessage += std::to_string(MIN_COST);
		throw std::exception(exceptionMessage.c_str());
	}
	if (discount < 0) {
		std::string exceptionMessage = "Product can't be created because the discount < ";
		exceptionMessage += std::to_string(MIN_DISCOUNT);
		throw std::exception(exceptionMessage.c_str());
	}
	if (discount > 100) {
		std::string exceptionMessage = "Product can't be created because the discount > ";
		exceptionMessage += std::to_string(MAX_DISCOUNT);
		throw std::exception(exceptionMessage.c_str());
	}

	mBarCode = barCode;
	mName = name;
	mCost = cost;
	mDiscount = discount;
}

Product& Product::operator=(const Product& other) {
	if (*this == other) {
		return *this;
	}
	mBarCode = other.mBarCode;
	mName = other.mName;
	mCost = other.mCost;
	mDiscount = other.mDiscount;
	return *this;
}
