#include <gtest/gtest.h>

#define TESTING

#ifdef TESTING

int main() {
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
#endif // !TESTING

