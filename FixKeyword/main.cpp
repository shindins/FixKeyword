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
std::vector<KeyWordNode> weekContainer[MaxWeekSize];
std::vector<KeyWordNode> weekEndContainer[MaxWeekendSize];

std::map <std::string, std::vector<KeyWordNode>> mp;


void noHitKeyWord(int idx, std::string keyWord, std::vector<KeyWordNode> container[], int flag) {

	if (container[idx].size() < MaxWeekSize) {
		container[idx].push_back({ keyWord, uzScore });
		std::sort(container[idx].begin(), container[idx].end());
		return;
	}

	if (container[idx].back().keyWordScore < uzScore) {
		container[idx].pop_back();
		container[idx].push_back({ keyWord, uzScore });
		std::sort(container[idx].begin(), container[idx].end());
	}
}

std::string chalDDuckHitKeyword(int idx, std::string keyWord, std::vector<KeyWordNode> container[]) {

	for (KeyWordNode& node : container[idx]) {
		if (similer(node.keyWord, keyWord)) {
			return node.keyWord;
		}
	}
	return "";
}

bool completeHitKeyWord(int idx, std::string keyWord, std::vector<KeyWordNode> container[]) {

	long long int calcScore = 0;

	for (KeyWordNode& node : mp[keyWord]) {

		if (node.keyWord == keyWord) {
			calcScore = node.keyWordScore + (node.keyWordScore * weightScore);

			if (calcScore >= MaxIntSize) { // ÀçÁ¤·Ä
				uzScore = 10;
			}
			else {
				node.keyWordScore += (node.keyWordScore * weightScore);
			}
			return true;
		}
	}

	//for (KeyWordNode& node : container[idx]) {

	//	if (node.keyWord == keyWord) { // Complete Hit

	//		calcScore = node.keyWordScore + (node.keyWordScore * weightScore);

	//		if (calcScore >= MaxIntSize) { // ÀçÁ¤·Ä
	//			uzScore = 10;
	//		}
	//		else {
	//			node.keyWordScore += (node.keyWordScore * weightScore);
	//		}
	//		return true;
	//	}
	//}
	return false;
}

int findWeekDayIdx(std::string weekDay) {

	if (weekDay == "monday") return 0;
	if (weekDay == "tuesday") return 1;
	if (weekDay == "wednesday") return 2;
	if (weekDay == "thursday") return 3;
	if (weekDay == "friday") return 4;
	if (weekDay == "saturday") return 5;
	if (weekDay == "sunday") return 6;

	return -1;
}

int checkWeekDay(std::string weekDay) {

	if (weekDay == "monday") return 0;
	if (weekDay == "tuesday") return 0;
	if (weekDay == "wednesday") return 0;
	if (weekDay == "thursday") return 0;
	if (weekDay == "friday") return 0;
	if (weekDay == "saturday") return 1;
	if (weekDay == "sunday") return 1;

	return -1;
}

std::string executeProcess(std::string keyWord, std::string weekDay) {

	std::string ret = keyWord;

	int weekDayIdx = findWeekDayIdx(weekDay);
	int isWeekDay = checkWeekDay(weekDay);

	// ¿Ïº® Hit
	bool weekDayCompleteHit = completeHitKeyWord(weekDayIdx, keyWord, weekContainer);
	bool weekEndCompleteHit = completeHitKeyWord(isWeekDay, keyWord, weekEndContainer);
	
	if (weekDayCompleteHit) return ret;

	// Âû¶± Hit
	std::string weekDayChalDDuckHit = chalDDuckHitKeyword(weekDayIdx, keyWord, weekContainer);
	std::string weekEndChalDDuckHit = chalDDuckHitKeyword(isWeekDay, keyWord, weekEndContainer);

	if (weekDayChalDDuckHit != "") return weekDayChalDDuckHit;
	if (weekEndChalDDuckHit != "") return weekEndChalDDuckHit;

	return ret;
}

bool readKeyWordFile(const std::string fileName) {

	std::ifstream file(fileName);
	
	if (!file.is_open()) return false;

	std::string inputKeyword = "";
	std::string inputWeekDay = "";

	while (file) {
		file >> inputKeyword >> inputWeekDay;
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