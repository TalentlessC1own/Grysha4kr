#include "Algoritm.h"
#include "File.h"
std::string* GetText(int& size)
{
	std::string* tmp_arr = NULL;
	std::string buffer = "";
	std::vector<std::string>tmp_text;
	std::cout << "Введите текст. "
		<< "По окончание ввода введите пустую строку" << std::endl;
	do {
		std::getline(std::cin, buffer);
		if (buffer.size() > 0) {
			
			tmp_text.push_back(buffer);
		}
	} while (buffer != "");
	size = static_cast<int>(tmp_text.size());
	tmp_arr = new std::string[size];
	for (int i = 0; i < size; i++) {
		tmp_arr[i] = tmp_text[i];
	}
	return tmp_arr;
}
bool Isalpha(char c) {
	return c >= 'а' && c <= 'я' || c >= 'А' && c <= 'Я'|| c >= 'a' && c <= 'z'|| c >= 'A' && c <= 'Z'
		|| c == 'ё' || c == 'Ё'; 
}
void CopyToMapStatistic(std::map<std::string, int>& statistic_mp, std::vector<std::pair<std::string, int>>& vec){
	for (std::vector<std::pair<std::string, int>>::iterator vec_it = vec.begin(); vec_it != vec.end(); vec_it++) {
		statistic_mp[vec_it->first] += vec_it->second;
		}
}
std::map<std::string, int> MapFilter(std::map<std::string, int> mp) {
	std::map<std::string, int> tmp_mp;
	for (std::map<std::string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		std::string tmp_str = it->first;

		for (int i = 0; i < tmp_str.size(); i++) {
			if (i > 0&&i< tmp_str.size()-1) {
				if (Isalpha(tmp_str[i + 1]) && tmp_str[i] == '-' && Isalpha(tmp_str[i - 1])) {
					continue;
				}
			}

			if (!Isalpha(tmp_str[i])) {
				tmp_str[i] = ' ';
			}
		}
		std::stringstream strmp(tmp_str);
		std::string temp;
		while (strmp >> temp) {
			tmp_mp[temp]+=it->second;
		}
	}
	return tmp_mp;
}
void WordsCheck(int size, std::string* textarr, std::vector<std::pair<std::string, int>> &vec, std::map<std::string, int>& statistic_mp)
{
	std::map<std::string, int> mp;
	for (int i = 0; i < size; i++) {
		std::stringstream strm(textarr[i]);
		std::string temp;
		while (strm >> temp) {
			mp[temp]++;
		}
	}
	mp=MapFilter(mp);
	for (std::map<std::string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		std::pair<std::string, int>pair(it->first, it->second);
		vec.push_back(pair);
	}

	std::cout << "Статистика:" << std::endl;
	for (std::vector<std::pair<std::string, int>>::iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << it->first << "=>" << it->second << std::endl;	
	}
	CopyToMapStatistic(statistic_mp, vec);
	StatisticAdd(statistic_mp);
}
