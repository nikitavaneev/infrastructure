#include <gtest/gtest.h>
#include <vector>
#include "heap.h"

using std::vector;
using std::make_pair;

TEST(Heap, can_create) {
  ASSERT_NO_THROW(heap<int>());
}

TEST(Heap, can_add) {
  heap<int> t;
  ASSERT_NO_THROW(t.add(4));
  ASSERT_NO_THROW(t.add(2));
  ASSERT_NO_THROW(t.add(1));
}

TEST(Heap, can_insert_in_empty_heap) {
  heap<int> t;
  ASSERT_NO_THROW(t.add(1));
}

TEST(Heap, can_find_min) {
  heap<int> t;
  t.add(1);
  ASSERT_NO_THROW(t.min());
}

TEST(Heap, throw_min) {
  heap<int> t;
  ASSERT_ANY_THROW(t.min());
}

TEST(Heap, can_delete_head) {
  heap<int> t;
  t.add(4);
  ASSERT_NO_THROW(t.delmin());
}
