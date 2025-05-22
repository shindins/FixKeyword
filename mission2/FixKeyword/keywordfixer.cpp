#include "keywordfixer.h"

#include <iostream>

#include "config.h"
#include "util.h"
#include "keywordchecker.h"

// global 
extern std::map <std::string, std::vector<KeyWordNode>> weekDayContainer;
extern std::map <std::string, std::vector<KeyWordNode>> weekEndContainer;

std::string KeyWordFixer::executeProcess(const std::string& keyWord, const std::string& dayOftheWeek) {

	KeyWordChecker* checker = new KeyWordChecker();
	KeyWordUtil* util = new KeyWordUtil();
	
	std::string ret = keyWord;

	std::string isWeekEnd = util->checkWeekEndDay(dayOftheWeek);
	

	// ¿Ïº® Hit
	bool weekDayCompleteHit = checker->completeHitKeyWord(dayOftheWeek, keyWord, weekDayContainer);
	bool weekEndCompleteHit = checker->completeHitKeyWord(isWeekEnd, keyWord, weekEndContainer);

	if (weekDayCompleteHit) return ret;

	// Âû¶± Hit
	std::string weekDayChalDDuckHit = checker->chalDDuckHitKeyword(dayOftheWeek, keyWord, weekDayContainer);
	std::string weekEndChalDDuckHit = checker->chalDDuckHitKeyword(isWeekEnd, keyWord, weekEndContainer);

	if (weekDayChalDDuckHit != "") return weekDayChalDDuckHit;
	if (weekEndChalDDuckHit != "") return weekEndChalDDuckHit;

	// ¿Ïº®, Âû¶±µµ ¾Æ´Ñ case
	checker->noHitKeyWord(dayOftheWeek, keyWord, weekDayContainer);
	checker->noHitKeyWord(isWeekEnd, keyWord, weekEndContainer);
	return ret;
}

bool KeyWordFixer::readKeyWordFile(const std::string& fileName) {

	std::ifstream file(fileName);

	if (!file.is_open()) return false;

	std::string keyWord = "";
	std::string dayOftheWeek = "";
	while (file) {
		file >> keyWord >> dayOftheWeek;
		executeProcess(keyWord, dayOftheWeek);
		uzScore++;
		// std::cout << inputKeyword << ' ' << inputWeekDay << '\n';
	}
	file.close();
	return true;
}