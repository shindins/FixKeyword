#ifndef KEYWORDFIXER_H_
#define KEYWORDFIXER_H_

#include "keywordfixer_interface.h"
#include <fstream>
#include <string>

class KeyWordFixer : public IKeyWordFixer{
public:
	std::string executeProcess(const std::string& keyWord, const std::string& dayOftheWeeky);
	bool readKeyWordFile(const std::string& fileName);
};

#endif // !KEYWORDFIXER_H_
