#pragma once
#include <string>
#include <unordered_map>
template <typename T> class EnumParser {
	
public:
	std::unordered_map<std::string, T> enumMap;
	EnumParser() {};

	T parseEnum(const std::string &value) {
		typename std::unordered_map <std::string, T>::iterator iValue = enumMap.find(value);
		if (iValue == enumMap.end())
			std::cout << "Error parseando enum" << std::endl;
		return iValue->second;
	}
};