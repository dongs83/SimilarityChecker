#include "gmock/gmock.h"

class SimilarityChecker {
public:
	int check(std::string str1, std::string str2) {
		int ret = 0;
		if (isSameString(str1, str2))
			return 100;

		if (isDoubleLength(str1, str2))
			return 0;

		if (str1.length() == str2.length()) {
			ret += 60;
		}

		else {
			int len1 = (str1.length() >= str2.length()) ? str1.length() : str2.length();
			int len2 = (str1.length() <= str2.length()) ? str1.length() : str2.length();
			ret += (1 - (len1 - len2)) / len2 * 60;
		}

		return ret;
	}
	bool isDoubleLength(std::string& str1, std::string& str2)
	{
		int length1 = str1.length();
		int length2 = str2.length();
		return (length1 > length2) ? 
			length1 >= length2 * 2 : length1 * 2 >= length2;
	}
	bool isSameString(std::string& str1, std::string& str2)
	{
		return str1 == str2;
	}
};
