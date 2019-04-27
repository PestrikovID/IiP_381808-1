#pragma once
#include <string>

//класс для хранения штрих кода
//сделан для того, чтобы объект (штрих код) мог сам проверять себя на корректность
class BarCode
{
public:
	
	BarCode() {
		mValue = DEFAULT_BAR_CODE_VALUE;
	}
	BarCode(std::string value);
	BarCode(const BarCode& other) {
		mValue = other.mValue;
	}

	std::string getValue() { return mValue; }

	BarCode& operator=(const BarCode& other);

	bool operator==(const BarCode& other) {
		return mValue == other.mValue;
	}
	
	static std::string getDefaultBarCodeValue() {
		return DEFAULT_BAR_CODE_VALUE;
	}		

private:
	//само значение штрих кода
	std::string mValue;

	bool isValueCorrect(std::string value);

	//Длина штрих кода
	const int BAR_CODE_LENGTH = 4;
	//Базовое значение штрих кода (если не задано клиентом класса)
	static const std::string DEFAULT_BAR_CODE_VALUE;
};






