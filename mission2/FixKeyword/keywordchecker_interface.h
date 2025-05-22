#ifndef KEYWORDCHECKER_INTERFACE_H_
#define KEYWORDCHECKER_INTERFACE_H_

#include <string>
#include <map>
#include <vector>

struct KeyWordNode;

class IKeyWordChecker {
public:
	virtual void noHitKeyWord(std::string dayOftheWeek, std::string keyWord, std::map <std::string, std::vector<KeyWordNode>>& container) = 0;
	virtual std::string chalDDuckHitKeyword(std::string dayOftheWeek, std::string keyWord, std::map <std::string, std::vector<KeyWordNode>> container) = 0;
	virtual bool completeHitKeyWord(std::string dayOftheWeek, std::string keyWord, std::map <std::string, std::vector<KeyWordNode>> container) = 0;
};


#endif // !KEYWORDCHECKER_INTERFACE_H_
