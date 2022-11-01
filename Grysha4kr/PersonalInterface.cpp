#include "PersonalInterface.h"


void ShowGreetings()
{
	std::cout << "Кр 4 Гриша 415" << std::endl;
}

void ShowSortChoice()
{
	std::cout << "Какой вид сортировки данных в файле вы предпочитаете?" << std::endl;
	std::cout << "1)По Алфавиту" << std::endl;
	std::cout << "2)По Количеству вхождений" << std::endl;
}
void ShowCountChoice()
{
	std::cout << "Какое количество слов вы хотите чтобы было записано в файл?" << std::endl;
}

void ShowInputChoice()
{
	std::cout << "Как ввод данных хотитие использовать?" << std::endl;
	std::cout << "1)Консольный" << std::endl;
	std::cout << "2)Файловый" << std::endl;
}

void ShowOutputChoise()
{
	std::cout << "Вы хотите перезаписать данный файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Ввести новое имя(путь к файлу)" << std::endl;
}
void ShowOutputType() {
	std::cout << "Вы хотите записать данные в файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
}

