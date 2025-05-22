#include "keywordchecker.h"

#include <algorithm>
#include <iostream>

#include "config.h"
#include "util.h"


void KeyWordChecker::noHitKeyWord(std::string dayOftheWeek, std::string keyWord, std::map <std::string, std::vector<KeyWordNode>>& container) {

	if (container[dayOftheWeek].size() < MaxWeekSize) {
		container[dayOftheWeek].push_back({ keyWord, uzScore });
		std::sort(container[dayOftheWeek].begin(), container[dayOftheWeek].end());
		return;
	}

	if (container[dayOftheWeek].back().keyWordScore < uzScore) {
		container[dayOftheWeek].pop_back();
		container[dayOftheWeek].push_back({ keyWord, uzScore });
		std::sort(container[dayOftheWeek].begin(), container[dayOftheWeek].end());
	}
}

std::string KeyWordChecker::chalDDuckHitKeyword(std::string dayOftheWeek, std::string keyWord, std::map <std::string, std::vector<KeyWordNode>> container) {

	KeyWordUtil* util = new KeyWordUtil();

	for (KeyWordNode& oneKeyWord : container[dayOftheWeek]) {
		if (util->similer(oneKeyWord.keyWord, keyWord)) {
			return oneKeyWord.keyWord;
		}
	}
	delete util;
	return "";
}

bool KeyWordChecker::completeHitKeyWord(std::string dayOftheWeek, std::string keyWord, std::map <std::string, std::vector<KeyWordNode>> container) {

	KeyWordUtil* util = new KeyWordUtil();

	long long int calcScore = 0;
	for (KeyWordNode& oneKeyWord : container[dayOftheWeek]) {

		if (oneKeyWord.keyWord == keyWord) {
			calcScore = oneKeyWord.keyWordScore + (oneKeyWord.keyWordScore * WeightScore);

			std::cout << calcScore << '\n';

			//if (calcScore >= MaxIntSize || uzScore >= MaxIntSize) { // ÀçÁ¤·Ä
			//	uzScore = 10;
			//	util->reArrangeContainer();
			//}
			
			oneKeyWord.keyWordScore += (oneKeyWord.keyWordScore * WeightScore);
			

			delete util;
			return true;
		}
	}
	delete util;
	return false;
}