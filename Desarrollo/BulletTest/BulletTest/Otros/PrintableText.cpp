#include "PrintableText.h"

PrintableText::PrintableText() :
	maxPrintableTexts(20),
	durationTime(seconds(3))
{
}

const std::string & PrintableText::addPrintText(const std::string & str)
{
	//Si nos pasamos de textos en pantalla borramos el primero en entrar(head)
	if (PrintText.size() > (std::size_t)maxPrintableTexts) {
		//Obtenemos el string de la cabeza
		std::string auxStr = PrintText.back();
		//Borramos del current text el tamaño + 1 para el \n
		currentText.erase(0, auxStr.size() + 1);

		PrintText.pop_back();
	}

	//Añadimos el nuevo al final
	PrintText.push_back(str);

	//Lo añadimos con un salto de linea al print final
	currentText.append(str + "\n");

	clockPrintableText.restart();

	return currentText;
}
