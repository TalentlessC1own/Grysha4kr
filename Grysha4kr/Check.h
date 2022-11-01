#pragma once
#include<iostream>
#include <string>
#include<fstream>
#include <limits>
int GetPositiveInt();
std::string CheckLineS(std::ifstream& file);
int GetChoise();
struct MyExcept : public std::exception {
	const char* what() const throw () {
		return "exeption";
	}
};




