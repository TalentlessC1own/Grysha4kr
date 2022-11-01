#pragma once
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector> 
#include <map> 
#include "PersonalInterface.h"
#include "Algoritm.h"
void StatisticAdd(std::map<std::string, int> statistic_mp);
void FileOutput(std::vector<std::pair<std::string, int>>& vec);
std::string* InputDataFileInput(int &size);
void InputDataFileOutput(std::string* text,int size);