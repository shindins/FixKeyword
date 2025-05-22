#ifndef KEYWORD_MAIN_H_
#define KEYWORD_MAIN_H_

#include <map>
#include <vector>
#include <string>

#include "config.h"

void noHitKeyWord(std::string dayOftheWeek, std::string keyWord, std::map <std::string, std::vector<KeyWordNode>> container);
std::string chalDDuckHitKeyword(std::string dayOftheWeek, std::string keyWord, std::map <std::string, std::vector<KeyWordNode>> container);
bool completeHitKeyWord(std::string dayOftheWeek, std::string keyWord, std::map <std::string, std::vector<KeyWordNode>> container);

void reArrangeContainer();
std::string checkWeekEndDay(const std::string& dayOftheWeek);

std::string executeProcess(const std::string& keyWord, const std::string& dayOftheWeeky);
bool readKeyWordFile(const std::string& fileName);

#endif // !KEYWORD_MAIN_H_

