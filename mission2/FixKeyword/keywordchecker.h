#ifndef KEYWORDCHECKER_H_
#define KEYWORDCHECKER_H_

#include "keywordchecker_interface.h"

class KeyWordChecker : public IKeyWordChecker {
public:
	void noHitKeyWord(std::string dayOftheWeek, std::string keyWord, std::map <std::string, std::vector<KeyWordNode>>& container);
	std::string chalDDuckHitKeyword(std::string dayOftheWeek, std::string keyWord, std::map <std::string, std::vector<KeyWordNode>> container);
	bool completeHitKeyWord(std::string dayOftheWeek, std::string keyWord, std::map <std::string, std::vector<KeyWordNode>> container);
};


#endif // !KEYWORDCHECKER_H_
