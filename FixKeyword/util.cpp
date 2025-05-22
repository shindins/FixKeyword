#include "util.h"

#include <vector>
#include <map>

#include "config.h"
#include "logic_levenshtein.h"
#include "logic_manager.h"

// global 
extern std::map <std::string, std::vector<KeyWordNode>> weekDayContainer;
extern std::map <std::string, std::vector<KeyWordNode>> weekEndContainer;


// 점수 환산
bool KeyWordUtil::similer(const std::string& a, const std::string& b) {
	if (a.empty() && b.empty()) return false;
	if (a.empty() || b.empty()) return false;

	// Strategy Pattern
	LogicManager* logic = new LogicManager();
	logic->changeLogic(new LogicLevenShtein());
	int dist = logic->executeLogic(a, b);

	int max_len = std::max(a.length(), b.length());
	// 유사도 비율 (1.0: 완전히 같음, 0.0: 전혀 다름)
	double similarity = 1.0 - (double)dist / max_len;

	int score = 1 + static_cast<int>(similarity * 99);

	if (score >= 80) return true;
	return false;
}

//void KeyWordUtil::reArrangeContainer() {
//
//	int defaultScore = 0;
//
//	for (const auto& oneDay : weekDayContainer) {
//		defaultScore = 0;
//
//		for (KeyWordNode& oneNode : weekDayContainer[oneDay.first]) {
//			oneNode.keyWordScore = ++defaultScore;
//		}
//	}
//
//	for (const auto& oneDay : weekEndContainer) {
//		defaultScore = 0;
//
//		for (KeyWordNode& oneNode : weekEndContainer[oneDay.first]) {
//			oneNode.keyWordScore = ++defaultScore;
//		}
//	}
//}

std::string KeyWordUtil::checkWeekEndDay(const std::string& dayOftheWeek) {

	if (dayOftheWeek == "monday") return "weekday";
	if (dayOftheWeek == "tuesday") return "weekday";
	if (dayOftheWeek == "wednesday") return "weekday";
	if (dayOftheWeek == "thursday") return "weekday";
	if (dayOftheWeek == "friday") return "weekday";
	if (dayOftheWeek == "saturday") return "weekend";
	if (dayOftheWeek == "sunday") return "weekend";
}