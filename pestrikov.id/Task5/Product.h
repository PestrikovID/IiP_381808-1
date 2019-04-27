#pragma once
#include <string>
#include <ctime>
#include <random>
#include "BarCode.h"

// Описание товара
class Product
{
private:

	// Штрих код
	BarCode mBarCode;
	// Наименование товара
	std::string mName;
	// Цена
	int mCost;
	// Скидка
	int mDiscount;

	const std::string DEFAULT_NAME = "Not defined";
	const int MIN_COST = 0;
	const int MIN_DISCOUNT = 0;
	const int MAX_DISCOUNT = 100;	

public:
	Product();
	Product(BarCode barCode, std::string name, int cost, int discount);

	int getDiscount() const { return mDiscount; }
	BarCode getBarCode() const { return mBarCode; }
	std::string getName() const { return mName; }
	int getCost() const { return mCost; }

	bool operator==(const Product& other) {
		return mBarCode == other.mBarCode;
	}

	Product& operator=(const Product& other);		
};




