#ifndef KEYWORD_CONFIG_H_
#define KEYWORD_CONFIG_H_

#include <string>

struct WeekNode {
	std::string weekDay;
	std::string keyWord;
};

struct KeyWordNode {
	std::string keyWord;
	int keyWordScore;

	bool operator<(const KeyWordNode& otherNode) const {
		return keyWordScore < otherNode.keyWordScore;
	}
};

const int MaxWeekSize = 7;
const int MaxWeekendSize = 2;

const int searchDBSize = 10;
const int MaxIntSize = 2100000000;
const double WeightScore = 0.1;

int uzScore = 10;


#endif // !KEYWORD_CONFIG_H_
