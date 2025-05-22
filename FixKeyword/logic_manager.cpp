#include "logic_manager.h"

int LogicManager::executeLogic(const std::string& a, const std::string& b) {
	return logic->similarityLogic(a,b);
}

void LogicManager::changeLogic(LogicStrategy* pLogic) {
	if (logic) delete logic;
	logic = pLogic;
}