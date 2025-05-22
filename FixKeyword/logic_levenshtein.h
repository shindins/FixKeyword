
#ifndef LOGIC_LEVENSHTEIN_H_
#define LOGIC_LEVENSHTEIN_H_

#include <string>

#include "logic_strategy.h"

class LogicLevenShtein : public LogicStrategy {
public:
	int similarityLogic(const std::string& a, const std::string& b);
};

#endif // !LOGIC_LEVENSHTEIN_H_



