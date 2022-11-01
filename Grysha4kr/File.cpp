#include "File.h"
bool comp(std::pair <std::string, int>  a, std::pair <std::string, int> b) {
	return a.second > b.second;
}
bool cmp(std::pair <std::string, int>  a, std::pair <std::string, int> b) {
	return _strcmpi(a.first.c_str(), b.first.c_str()) < 0;
};
struct MyException : public std::exception {
	const char* what() const throw () {
		return "exeption";
	}
};
void StatisticAdd(std::map<std::string, int> statistic_mp)
{
	std::map<std::string, int> file_mp;
	std::string line;
	std::string file_name = "Static.txt";
	std::ifstream Infile;
	std::ofstream Outfile;
	Infile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	Outfile.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	try {
		try {
			Infile.open(file_name);
		}
		catch (const std::exception&) {

			throw MyException();
		}
		try {

			do {
				std::string tmp_word;
				std::string tmp_num;

				line = CheckLineS(Infile);
				for (int i = 0; i < line.size(); i++) {
					if (i > 0 && i < line.size() - 1) {
						if (Isalpha(line[i + 1]) && line[i] == '-' && Isalpha(line[i - 1])) {
							tmp_word += line[i];
						}
					}
					if (Isalpha(line[i])) {
						tmp_word += line[i];
					}
					if (isdigit(line[i])) {
						tmp_num += line[i];
					}
				}
				if (stoi(tmp_num)>0) {
					file_mp[tmp_word] = stoi(tmp_num);
				}
			} while (true);
		}
		catch (MyExcept&) {
			Infile.close();
			throw MyException();
		}
	}
		catch (MyException& )
		{
			if (statistic_mp.size() != 0) {
				for (std::map<std::string, int>::iterator mp_it = statistic_mp.begin(); mp_it != statistic_mp.end(); mp_it++) {
					file_mp[mp_it->first] += mp_it->second;
				}
			}
			Outfile.open(file_name);
			for (std::map<std::string, int>::iterator mp_it = file_mp.begin(); mp_it != file_mp.end(); mp_it++) {
				Outfile << mp_it->first << "=>" << mp_it->second << std::endl;
			}
			Outfile.close();
		}
		
	
}
void FileOutput(std::vector<std::pair<std::string, int>>& vec)
{
	const int Yes = 1;
	
	std::string name;
	std::ofstream  FileRecorder;
	FileRecorder.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	std::ifstream CheckExist;
	CheckExist.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	while (true)
	{


		std::cout << "Введите имя файла или полный путь." << std::endl << "ENTER:";
		std::getline(std::cin, name);
		if (name.find(".txt") >= std::string::npos) {
			std::cout << "Не верный тип файла\n" << std::endl;
			continue;
		}
		try
		{
			CheckExist.open(name);
			std::cout << "Фаил с таким именем существует. " << std::endl
				<< "1 - Перезаписать этот файл " << std::endl
				<< "2 - Ввести новое имя файла " << std::endl;
			int var = GetChoise();
			if (var == Yes)
			{
				FileRecorder.open(name);
				CheckExist.close();
			}
			else
			{
				CheckExist.close();
				continue;
			}
		}
		catch (const std::exception&)
		{
			try
			{
				FileRecorder.open(name);
			}
			catch (const std::exception&)
			{
				std::cout << " Ошибка сохранения " << std::endl;
				continue;
			}

		}
		break;
	}

	ShowSortChoice();
	int user_choice = GetChoise();
	ShowCountChoice();
	int size = GetPositiveInt();
	if (size > vec.size()) { size = static_cast<int>(vec.size()); }
	
	switch (user_choice)
	{
	case 1:
		std::sort(vec.begin(), vec.end(), cmp);
		for (int i = 0; i < size;i++) {
			FileRecorder << vec[i].first <<"=>"<< vec[i].second << std::endl;
		}
		break;
	case 2:
		std::sort(vec.begin(), vec.end(), comp);
		for (int i = 0; i < size; i++) {
			FileRecorder << vec[i].first << "=>" << vec[i].second << std::endl;
		}
		break;
	}
	std::cout << "Данные успешно сохранены" << std::endl;

	FileRecorder.close();
}
std::string* InputDataFileInput(int &size) {
	std::vector<std::string> tmp_vec;
	std::string file_name = "";
	std::ifstream file;
	std::string* str = nullptr;
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	
	while (true)
	{
		std::cout << "Введите имя файла. " << std::endl << "Ввод : ";
		std::cin >> file_name;
		try
		{
			file.open(file_name);
			std::cout << "Файл открыт успешно " << std::endl;
		}
		catch (const std::exception&)
		{
			std::cout << "Не верное имя файла или путь.Повторите ввод " << std::endl;
			continue;
		}
		try
		{
			std::string line;
			do{
				std::getline(file, line);
				tmp_vec.push_back(line);
			} while (true);
			
		}

		catch (const std::exception&) {
			str = new std::string[tmp_vec.size()];
			for (int i = 0; i < tmp_vec.size(); i++) {
				str[i] = tmp_vec[i];
			}
			std::cout << "Исходные данные" << std::endl;
			for (int i = 0; i < tmp_vec.size(); i++) {
				std::cout << str[i] << std::endl;
			}
			size = static_cast<int>(tmp_vec.size());
			file.close();
			break;
		}
	}

	return str;
}

void InputDataFileOutput(std::string* text, int size)
{
	const int Yes = 1;
	std::string name;
	std::ofstream  FileRecorder;
	FileRecorder.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	std::ifstream CheckExist;
	CheckExist.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	while (true)
	{
		std::cout << "Введите имя файла или полный путь." << std::endl << "ENTER:";
		std::getline(std::cin, name);
		if (name.find(".txt") >= std::string::npos) {
			std::cout << "Не верный тип файла\n" << std::endl;
			continue;
		}
		try
		{
			CheckExist.open(name);
			std::cout << "Файл с таким именем существует. " << std::endl
				<< "1 - Перезаписать этот файл " << std::endl
				<< "2 - Ввести новое имя файла " << std::endl;
			int var = GetChoise();
			if (var == Yes)
			{
				FileRecorder.open(name);
				CheckExist.close();
			}
			else
			{
				CheckExist.close();
				continue;
			}
		}
		catch (const std::exception&)
		{
			try
			{
				FileRecorder.open(name);
			}
			catch (const std::exception&)
			{
				std::cout << " Ошибка сохранения " << std::endl;
				continue;
			}

		}
		break;
	}
	for (int i=0; i < size; i++) {
		FileRecorder << text[i] << std::endl;
	}
	std::cout << "Данные успешно сохранены" << std::endl;

	FileRecorder.close();
}
