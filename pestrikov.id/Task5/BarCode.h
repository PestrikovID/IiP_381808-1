#pragma once
#include <string>

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
	std::string mValue;

	bool isValueCorrect(std::string value);

	const int BAR_CODE_LENGTH = 4;
	static const std::string DEFAULT_BAR_CODE_VALUE;
};






