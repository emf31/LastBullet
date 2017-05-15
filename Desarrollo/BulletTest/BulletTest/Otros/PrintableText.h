#pragma once
#include <iostream>
#include <vector>
#include <Clock.hpp>

class PrintableText {
public:
	PrintableText();

	//Imprime un texto por pantalla
	const std::string& addPrintText(const std::string& str);


	bool checkIfShouldClearText() {
		if (clockPrintableText.getElapsedTime().asSeconds() > durationTime.asSeconds()) {
			return true;
		}
	}

private:
	//String para imprimir por pantalla cualquier info de debug
	std::vector<std::string> PrintText;
	//Controla el maximo de mensajes que se imprimen al mismo tiempo
	int maxPrintableTexts;
	std::string currentText;
	Time durationTime;
	Clock clockPrintableText;


};