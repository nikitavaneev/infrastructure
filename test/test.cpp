#include <gtest/gtest.h>
#include "treefind.h"


TEST(Find, FindDontChangeTree) {
  CNode* t = CreateTree();

  find(&t, 5);

  ASSERT_EQ(t->val, 4);
  ASSERT_EQ(t->left->val, 2);
  ASSERT_EQ(t->right->val, 6);
  ASSERT_EQ(t->right->left->val, 5);
  ASSERT_EQ(t->right->right->val, 7);
  ASSERT_EQ(t->left->left->val, 1);
  ASSERT_EQ(t->left->right->val, 3);
}

TEST(Find, CanFind) {
  CNode* t = CreateTree();

  CNode* n = *(find(&t, 5));

  ASSERT_EQ(n->val, 5);
}

TEST(Find, FindReturnRightPosition) {
  CNode* t = CreateTree();

  CNode** n = find(&t, 8);
  CNode* nl = 0;

  ASSERT_EQ(*n, nl);

  *n = new CNode(8);

  CNode* nw = *(find(&t, 8));

  ASSERT_EQ(nw->val, 8);
}

int main(int ac, char* av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
