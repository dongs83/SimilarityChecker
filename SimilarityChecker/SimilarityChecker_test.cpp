#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

using std::string;

class Fixture : public testing::Test {
public:
	SimilarityChecker sc;
	void runCheck(int expected, string str1, string str2) {
		EXPECT_EQ(expected, sc.check(str1, str2));
	}
};

TEST_F(Fixture, score100) {
	runCheck(100, "abcd", "abcd");
}

TEST_F(Fixture, score0) {
	runCheck(0, "abcd", "abcdabcde");
	runCheck(0,  "abcdabcde", "abcd");
	runCheck(0, "abcdabcd", "abcd");
	runCheck(0, "ad", "abcd");
}

TEST_F(Fixture, length) {
	runCheck(60, "asd", "dsa");
}
