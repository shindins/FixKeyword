#ifndef LOGIC_MANAGER_H
#define LOGIC_MANAGER_H

#include <string>

#include "logic_strategy.h"

class LogicManager {
public:

	int executeLogic(const std::string& a, const std::string& b);
	void changeLogic(LogicStrategy* pLogic);

private:
	LogicStrategy* logic;
};

#endif // !LOGIC_MANAGER_H
