#include <gtest/gtest.h>
#include "massiv.h"

TEST(Addition, one_element) {
    int a[] = { 1 };
    int *b = mass(a, 1);
    EXPECT_EQ(b[0], 1);
}

TEST(Addition, massiv) {
    int a[] = { 1, 2, 3 };
    int *b = mass(a, 3);
    EXPECT_EQ(b[0], 6);
    EXPECT_EQ(b[1], 3);
    EXPECT_EQ(b[2], 2);
}

TEST(Addition, massiv1) {
    int a[] = { 1, 1, 1 };
    int *b = mass(a, 3);
    EXPECT_EQ(b[0], 1);
    EXPECT_EQ(b[1], 1);
    EXPECT_EQ(b[2], 1);
}
