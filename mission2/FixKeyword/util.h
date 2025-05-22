#ifndef KEYWORD_UTIL_H_
#define KEYWORD_UTIL_H_

#include <string>

class KeyWordUtil {
public:
	bool similer(const std::string& a, const std::string& b);
	void reArrangeContainer();
	std::string checkWeekEndDay(const std::string& dayOftheWeek);
};


#endif // !KEYWORD_UTIL_H_