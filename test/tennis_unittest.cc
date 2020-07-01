#include "gtest/gtest.h"

extern "C"
{
#include "tennis.h"
}

class TennisTest : public testing::Test {
protected:
    void SetUp() {
        reset();
    }

    void assertScoreEq(const char *expected) {
        char actual[50];
        score(actual);
        ASSERT_EQ(strcmp(actual, expected), 0);
    }
};

TEST_F(TennisTest, LoveAll) {
    assertScoreEq("Love All");
}

TEST_F(TennisTest, FifteenLove) {
    playerOneScore();

    assertScoreEq("Fifteen Love");
}

TEST_F(TennisTest, ThirtyLove) {
    playerOneScore();
    playerOneScore();

    assertScoreEq("Thirty Love");
}

TEST_F(TennisTest, FortyLove) {
    playerOneScore();
    playerOneScore();
    playerOneScore();

    assertScoreEq("Forty Love");
}

TEST_F(TennisTest, LoveFifteen) {
    playerTwoScore();

    assertScoreEq("Love Fifteen");
}

TEST_F(TennisTest, LoveThirty) {
    playerTwoScore();
    playerTwoScore();

    assertScoreEq("Love Thirty");
}

TEST_F(TennisTest, FifteenThirty) {
    playerOneScore();
    playerTwoScore();
    playerTwoScore();

    assertScoreEq("Fifteen Thirty");
}

TEST_F(TennisTest, FifteenAll) {
    playerOneScore();
    playerTwoScore();

    assertScoreEq("Fifteen All");
}
