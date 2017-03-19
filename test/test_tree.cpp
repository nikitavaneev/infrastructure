#include <gtest/gtest.h>
#include "tree.h"

TEST(CreateTree, balance_tree) {
    int n = 5;
    int a[5] = { 1, 2, 3, 4, 5 };
    EXPECT_NO_THROW(Create(a, n));
}
TEST(CreateTree, balance1_tree) {
    int n = 5;
    int a[5] = { 1, 2, 3, 4, 5 };
    CNode* res = Create(a, n);
    EXPECT_EQ(res->val, 3);
    EXPECT_EQ(res->left->val, 1);
    EXPECT_EQ(res->right->val, 4);
    EXPECT_EQ(res->left->right->val, 2);
    EXPECT_EQ(res->right->right->val, 5);
}
TEST(CreateTriangleTree, empty_tree) {
    EXPECT_NO_THROW(Create(NULL, 0));
}
