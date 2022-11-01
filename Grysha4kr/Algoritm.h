#pragma once
#include "Check.h"
#include<iostream>
#include <sstream>
#include<vector> 
#include<map> 
#include<string>
std::string* GetText(int& size);
void WordsCheck(int size, std::string* textarr, std::vector<std::pair<std::string, int>>& vec, std::map<std::string, int>& statistic_mp);
bool Isalpha(char c);
std::map<std::string, int> MapFilter(std::map<std::string, int> mp);
void CopyToMapStatistic(std::map<std::string, int>& statistic_mp, std::vector<std::pair<std::string, int>>& vec);