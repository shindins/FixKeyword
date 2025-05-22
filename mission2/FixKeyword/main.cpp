#include "main.h"

// #define TESTING

// global 
std::map <std::string, std::vector<KeyWordNode>> weekDayContainer;
std::map <std::string, std::vector<KeyWordNode>> weekEndContainer;

#ifndef TESTING

int main() {
	
	const std::string fileName = "keyword_weekday_500.txt";

	KeyWordFixer* fixer = new KeyWordFixer();

	if (fixer->readKeyWordFile(fileName));
	delete fixer;
	

	return 0;
}

#endif !TESTING