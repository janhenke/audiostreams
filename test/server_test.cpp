//
// Created by jan on 26.12.17.
//

#include <gtest/gtest.h>

GTEST_TEST(ServerTest, dummy_test_case) {
	EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}