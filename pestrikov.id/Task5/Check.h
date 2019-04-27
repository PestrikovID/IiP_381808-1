#pragma once
#include "Array.h"
#include "Product.h"

//чек
class Check
{
public:
	
	// добавить товар в чек
	void addProduct(Product product);
	// возращает строку, состовл€ющую содержимое чека
	std::string getDescription();

	// возвращает полную стоимость всех товаров в чеке
	int getTotalCost() { return mTotalCost; }
	// возращает общую скидку
	int getTotalDiscount() { return mTotalDiscount; }
	
	int calculateFinalTotalCost() {
		return mTotalCost - mTotalDiscount;
	}

	//очищает все пол€ 
	void clear();

private:
	// “овары, добавленные в чек
	Array<Product> mProducts;
	//  оличества товаров каждого вида
	Array<int> mProductCounts;

	//ќбща€ стоимость всех товаров в чеке
	int mTotalCost = 0;
	// ќбща€ скидка всех товаров в чеке
	int mTotalDiscount = 0;
	
	//¬озращает описание отдельного товара (как оно будет выгл€деть в чеке)
	std::string getProductDescription(const Product& product, int count);	
};






