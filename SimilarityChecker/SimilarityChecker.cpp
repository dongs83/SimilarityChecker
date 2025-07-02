#include "gmock/gmock.h"

class SimilarityChecker {
public:
	int check(std::string str1, std::string str2) {
		double ret = 0;
		if (isSameString(str1, str2))
			return 100;

		if (isDoubleLength(str1, str2))
			return 0;

		ret += getLengthScore(str1, str2);

		return ret;
	}
	int getLengthScore(std::string& str1, std::string& str2)
	{
		double ret;
		if (str1.length() == str2.length()) {
			ret += 60;
		}
		else {
			double len1 = (str1.length() >= str2.length()) ? str1.length() : str2.length();
			double len2 = (str1.length() <= str2.length()) ? str1.length() : str2.length();
			ret += (1 - (len1 - len2)) / len2 * 60;
			return static_cast<int>(ret);
		}
	}
	bool isDoubleLength(std::string& str1, std::string& str2)
	{
		int len1 = str1.length();
		int len2 = str2.length();

		if (len1 > len2)
			return (len1 >= (len2 * 2)) ? true : false;

		return ((len1 * 2) <= len2) ? true : false;
	}
	bool isSameString(std::string& str1, std::string& str2)
	{
		return str1 == str2;
	}
};
