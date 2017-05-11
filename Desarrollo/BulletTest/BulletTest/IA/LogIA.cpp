#include "LogIA.h"
#include <iostream>

std::vector<std::string> LogIA::log = std::vector<std::string>();

void LogIA::writeLog()
{
	std::cout << "********************** LOG DE LA IA *******************************" << std::endl;
	for (size_t i = 0; i < log.size(); i++) {
		std::cout << log.at(i) << std::endl;
	}
	std::cout << "******************************************************************" << std::endl<<std::endl;
}
