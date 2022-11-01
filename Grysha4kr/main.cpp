

#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <conio.h>
#include"Algoritm.h"
#include"PersonalInterface.h"
#include "Check.h"
#include "File.h"
#define QUIT 27

enum ManualInputsOrFileInput
{
	manual_input = 1,
	file_input = 2,
};
int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "RU");
	int UserChoice = 0;
	const int yes = 1;
	do {
		std::string* text=nullptr ;
		std::vector<std::pair<std::string, int>> vec;
		std::map<std::string, int> statistic_mp;
		int size = 0;
		ShowGreetings();
		ShowInputChoice();
		UserChoice = GetChoise();
		switch (UserChoice)
		{
		case  (manual_input):
			text = GetText(size);
			ShowOutputType();
			UserChoice = GetChoise();
			if (UserChoice == yes) {
				InputDataFileOutput(text, size);
			}
			break;
		case (file_input):
			text = InputDataFileInput(size);
			break;
		}
		WordsCheck(size, text, vec, statistic_mp);
		if (vec.size() == 0) {
			std::cout << "Слов не обнаружено" << std::endl;
		}
		else {
			ShowOutputType();
			UserChoice = GetChoise();
			if (UserChoice == yes) {
				FileOutput(vec);
			}
		}
		delete[] text;
		text = nullptr;
		std::cout << "Нажмите Esc чтобы завершить работу программы." << std::endl;
		std::cout << "Нажмите Enter чтобы продолжить." << std::endl;
		UserChoice = _getch();
	} while (UserChoice != QUIT);
	return 0;
}
