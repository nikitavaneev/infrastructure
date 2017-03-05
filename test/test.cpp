#include <gtest/gtest.h>
#include "add.h"

TEST(find, NullTree) {
    CNode* tree = 0;
    CNode* res = find(tree, 1);
    EXPECT_EQ(res, tree);
}

TEST(find, left) {
    CNode* tree = new CNode(5);
    tree->left = new CNode(6);
    tree->right = new CNode(4);
    tree->right->right = new CNode(3);
    CNode* res = find(tree, 6);
    EXPECT_EQ(6, res->value);
}

TEST(find, right) {
    CNode* tree = new CNode(5);
    tree->left = new CNode(6);
    tree->right = new CNode(4);
    tree->right->right = new CNode(3);
    CNode* res = find(tree, 3);
    EXPECT_EQ(3, res->value);
}

int main(int ac, char* av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
