#include "main.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>
#include <algorithm>
#include <map>

#include "config.h"
#include "util.h"

// global 
std::map <std::string, std::vector<KeyWordNode>> weekDayContainer;
std::map <std::string, std::vector<KeyWordNode>> weekEndContainer;

void noHitKeyWord(std::string dayOftheWeek, std::string keyWord, std::map <std::string, std::vector<KeyWordNode>> container) {

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

std::string chalDDuckHitKeyword(std::string dayOftheWeek, std::string keyWord, std::map <std::string, std::vector<KeyWordNode>> container) {

	for (KeyWordNode& oneKeyWord : container[dayOftheWeek]) {
		if (similer(oneKeyWord.keyWord, keyWord)) {
			return oneKeyWord.keyWord;
		}
	}
	return "";
}

bool completeHitKeyWord(std::string dayOftheWeek, std::string keyWord, std::map <std::string, std::vector<KeyWordNode>> container) {

	long long int calcScore = 0;

	for (KeyWordNode& oneKeyWord : container[dayOftheWeek]) {

		if (oneKeyWord.keyWord == keyWord) {
			calcScore = oneKeyWord.keyWordScore + (oneKeyWord.keyWordScore * WeightScore);

			if (calcScore > MaxIntSize) { // ÀçÁ¤·Ä
				uzScore = 10;
				reArrangeContainer();
			}
			else {
				oneKeyWord.keyWordScore += (oneKeyWord.keyWordScore * WeightScore);
			}
			return true;
		}
	}
	return false;
}

void reArrangeContainer() {

	int defaultScore = 0;

	for (const auto& oneDay : weekDayContainer) {
		defaultScore = 0;

		for (KeyWordNode& oneNode : weekDayContainer[oneDay.first]) {
			oneNode.keyWordScore = ++defaultScore;
		}
	}

	for (const auto& oneDay : weekEndContainer) {
		defaultScore = 0;

		for (KeyWordNode& oneNode : weekEndContainer[oneDay.first]) {
			oneNode.keyWordScore = ++defaultScore;
		}
	}
}

std::string checkWeekEndDay(const std::string& dayOftheWeek) {

	if (dayOftheWeek == "monday") return "weekday";
	if (dayOftheWeek == "tuesday") return "weekday";
	if (dayOftheWeek == "wednesday") return "weekday";
	if (dayOftheWeek == "thursday") return "weekday";
	if (dayOftheWeek == "friday") return "weekday";
	if (dayOftheWeek == "saturday") return "weekend";
	if (dayOftheWeek == "sunday") return "weekend";

	return "";
}

std::string executeProcess(const std::string& keyWord, const std::string& dayOftheWeek) {

	std::string ret = keyWord;

	std::string isWeekEnd = checkWeekEndDay(dayOftheWeek);

	// ¿Ïº® Hit
	bool weekDayCompleteHit = completeHitKeyWord(dayOftheWeek, keyWord, weekDayContainer);
	bool weekEndCompleteHit = completeHitKeyWord(isWeekEnd, keyWord, weekEndContainer);

	if (weekDayCompleteHit) return ret;

	// Âû¶± Hit
	std::string weekDayChalDDuckHit = chalDDuckHitKeyword(dayOftheWeek, keyWord, weekDayContainer);
	std::string weekEndChalDDuckHit = chalDDuckHitKeyword(isWeekEnd, keyWord, weekEndContainer);

	if (weekDayChalDDuckHit != "") return weekDayChalDDuckHit;
	if (weekEndChalDDuckHit != "") return weekEndChalDDuckHit;

	// ¿Ïº®, Âû¶±µµ ¾Æ´Ñ case
	noHitKeyWord(dayOftheWeek, keyWord, weekDayContainer);
	noHitKeyWord(isWeekEnd, keyWord, weekEndContainer);

	return ret;
}

bool readKeyWordFile(const std::string& fileName) {

	std::ifstream file(fileName);

	if (!file.is_open()) return false;

	std::string keyWord = "";
	std::string dayOftheWeek = "";

	while (file) {
		file >> keyWord >> dayOftheWeek;
		uzScore++;
		// std::cout << inputKeyword << ' ' << inputWeekDay << '\n';
	}
	file.close();
	return true;
}

int main() {
	try {
		if (readKeyWordFile("keyword_weekday_500.txt"));
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}
	return 0;
}