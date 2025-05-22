#ifndef INTERFACE_KEYWORDFIXER_H_
#define INTERFACE_KEYWORDFIXER_H_

#include <string>
#include <map>
#include <vector>

struct KeyWordNode;

class IKeyWordFixer {
public:
	virtual std::string executeProcess(const std::string& keyWord, const std::string& dayOftheWeeky) = 0;
	virtual bool readKeyWordFile(const std::string& fileName) = 0;
};

#endif // !INTERFACE_KEYWORDFIXER_H_


