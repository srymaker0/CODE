/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Nov 2020 03:49:27 PM CST
 ************************************************************************/

#include <stdio.h>
#include "ctest/test.h"

int add(int a, int b) {
    return a + b;
} 

TEST(testfunc, add) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_NE(add(1, 3), 5);
    EXPECT_EQ(add(2, 2), 4);
    EXPECT_EQ(add(0, 1), 1);
}

TEST(testfunc, add2) {
    EXPECT_EQ(add(2, 0), 2);
    EXPECT_GE(add(1, 3), 4);
    EXPECT_EQ(add(2, 2), 4);
    EXPECT_GT(add(0, 1), 1);
}
TEST(test, funcadd) {
    EXPECT_EQ(add(0, 1), 2);
    EXPECT_LE(add(1, 3), 4);
    EXPECT_LT(add(2, 2), 3);
    EXPECT_EQ(add(0, 1), 1);
}

int main() {
    return RUN_ALL_TESTS();
}
