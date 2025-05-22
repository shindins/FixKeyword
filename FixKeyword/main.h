#ifndef KEYWORD_MAIN_H_
#define KEYWORD_MAIN_H_

#include <vector>
#include <string>

#include "config.h"

void noHitKeyWord(int idx, std::string keyWord, std::vector<KeyWordNode> container[]);
std::string chalDDuckHitKeyword(int idx, std::string keyWord, std::vector<KeyWordNode> container[]);
bool completeHitKeyWord(int idx, std::string keyWord, std::vector<KeyWordNode> container[]);
int findWeekDayIdx(std::string weekDay);
int checkWeekDay(std::string weekDay);
std::string executeProcess(std::string keyWord, std::string weekDay);
bool readKeyWordFile(const std::string fileName);

#endif // !KEYWORD_MAIN_H_

