#include <gtest/gtest.h>
#include "../FixKeyword/util.h"


class CheckWeekEndDayTest:public ::testing::Test{

protected:
	KeyWordUtil util;
};

TEST_F(CheckWeekEndDayTest, weekdayTest) {
	const std::string dayOftheWeek = "monday";

	std::string actual = util.checkWeekEndDay(dayOftheWeek);
	std::string expect = "weekday";

	EXPECT_EQ(actual, expect);
}

TEST_F(CheckWeekEndDayTest, weekendDayTest) {
		const std::string dayOftheWeek = "sunday";
	
		std::string actual = util.checkWeekEndDay(dayOftheWeek);
		std::string expect = "weekend";
	
		EXPECT_EQ(actual, expect);
}

//TEST(CheckWeekEndDay, weekDayTest) {
//
//	const std::string dayOftheWeek = "monday";
//
//	std::string actual = checkWeekEndDay(dayOftheWeek);
//	std::string expect = "weekday";
//
//	EXPECT_EQ(actual, expect);
//}
//
//TEST(CheckWeekEndDay, weekendDayTest) {
//
//	const std::string dayOftheWeek = "sunday";
//
//	std::string actual = checkWeekEndDay(dayOftheWeek);
//	std::string expect = "weekend";
//
//	EXPECT_EQ(actual, expect);
//}