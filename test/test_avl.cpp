#include <gtest/gtest.h>
#include <vector>
#include "avl.h"

using std::vector;
using std::make_pair;

TEST(AVLtree, can_create1) {
  ASSERT_NO_THROW(avltree<int>());
}

TEST(AVLtree, can_insert_in_empty_tree) {
  avltree<int> t;
  ASSERT_NO_THROW(t.ins(1));
}

TEST(AVLtree, throw1) {
  avltree<int> t(5);
  ASSERT_ANY_THROW(t.ins(5));
}

TEST(AVLtree, can_find_min) {
  avltree<int> t;
  t.ins(1);
  ASSERT_NO_THROW(t.min());
}

TEST(AVLtree, throw_min) {
  avltree<int> t;
  ASSERT_ANY_THROW(t.min());
}

TEST(AVLtree, delete_min) {
  avltree<int> t;
  t.ins(4);
  t.ins(1);
  ASSERT_NO_THROW(t.delmin());
}

TEST(AVLtree, can_delete_head) {
  avltree<int> t;
  t.ins(4);
  ASSERT_NO_THROW(t.delmin());
}
