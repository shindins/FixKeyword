#ifndef KEYWORD_UTIL_H_
#define KEYWORD_UTIL_H_

#include <string>

int levenshtein(const std::string& a, const std::string& b);
bool similer(const std::string& a, const std::string& b);

#endif // !KEYWORD_UTIL_H_