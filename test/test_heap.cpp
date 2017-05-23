#include <gtest/gtest.h>
#include "three-heap.h"
TEST(heap, empty_heap) {
    EXPECT_NO_THROW(heap<int> h);
}
TEST(heap, correct_size) {
    heap<int> h;
    EXPECT_EQ(0, h.GetSize());
}

TEST(heap, Can_insert) {
    heap<int> h;
    EXPECT_NO_THROW(h.Insert(7));
}
TEST(heap, change_size) {
    heap<int> h;
    int size1 = h.GetSize();
    h.Insert(5);
    h.Insert(3);
    h.Insert(9);
    EXPECT_EQ(size1 + 3, h.GetSize());
}

TEST(heap, Can_compare_equal_heaps) {
    heap<int> h;
    heap<int> b;
    for (int i = 0; i < 10; i++) {
        h.Insert(i);
        b.Insert(i);
    }
    EXPECT_TRUE(h == b);
}
TEST(heap, Cant_compare_not_equal_heaps) {
    heap<int> h;
    heap<int> b;
    for (int i = 0; i < 10; i++) {
        h.Insert(i);
        b.Insert(10 - i);
    }
    EXPECT_FALSE(h == b);
}
TEST(heap, Cant_compare_not_equal_heaps2) {
    heap<int> h;
    heap<int> b;
    for (int i = 0; i < 10; i++) {
        h.Insert(i);
        b.Insert(10 - i);
    }
    EXPECT_TRUE(h != b);
}
TEST(heap, Check_get_elem_by_index) {
    heap<int> h;
    h.Insert(5);
    h.Insert(3);
    h.Insert(4);
    EXPECT_EQ(5, h[1]);
}
TEST(heap, get_elem_with_negative_index) {
    heap<int> h;
    EXPECT_ANY_THROW(h[-6]);
}
TEST(heap, get_elem_with_not_correct_index) {
    heap<int> h;
    for (int i = 0; i < 3; i++)
        h.Insert(i);
    EXPECT_ANY_THROW(h[10]);
}

TEST(heap, MinChild_with_neg_index) {
    heap<int> h;
    for (int i = 0; i < 3; i++)
        h.Insert(i);
    EXPECT_ANY_THROW(h.MinChild(-1));
}

TEST(heap, MinChild_with_more_index) {
    heap<int> h;
    for (int i = 0; i < 3; i++)
        h.Insert(i);
    EXPECT_ANY_THROW(h.MinChild(5));
}

TEST(heap, Can_correct_swap) {
    heap<int> h;
    h.Insert(4);
    h.Insert(8);
    h.Insert(3);
    h.Insert(12);
    h.Swap(0, 3);
    EXPECT_EQ(h[0], 12);
    EXPECT_EQ(h[3], 3);
}
TEST(heap, Swap_with_neg_index) {
    heap<int> h;
    h.Insert(2);
    h.Insert(5);
    h.Insert(1);
    h.Insert(13);
    EXPECT_ANY_THROW(h.Swap(0, -3));
}
TEST(heap, Swap_with_more_index) {
    heap<int> h;
    h.Insert(2);
    h.Insert(5);
    h.Insert(1);
    h.Insert(13);
    EXPECT_ANY_THROW(h.Swap(10, 2));
}
TEST(heap, Swap_change_size) {
    heap<int> h;
    h.Insert(4);
    h.Insert(8);
    h.Insert(3);
    h.Insert(12);
    int size1 = h.GetSize();
    h.Swap(0, 1);
    int size2 = h.GetSize();
    EXPECT_EQ(size1, size2);
}
TEST(heap, correctl_reduction) {
    heap<int> h;
    h.Insert(7);
    h.Reduction(0, -1);
    EXPECT_EQ(h[0], 8);
}
TEST(heap, Reduction_with_neg_index) {
    heap<int> h;
    for (int i = 0; i < 3; i++)
        h.Insert(i);
    EXPECT_ANY_THROW(h.Reduction(-3, 5));
}
TEST(heap, Reduction_with_more_index) {
    heap<int> h;
    for (int i = 0; i < 3; i++)
        h.Insert(i);
    EXPECT_ANY_THROW(h.Reduction(5, 5));
}
TEST(heap, Reduction_cant_change_size) {
    heap<int> h;
    for (int i = 0; i < 3; i++)
        h.Insert(i);
    int size1 = h.GetSize();
    h.Reduction(2, 4);
    int size2 = h.GetSize();
    EXPECT_EQ(size1, size2);
}
TEST(heap, Immertion_with_neg_index) {
    heap<int> h;
    for (int i = 0; i < 3; i++)
        h.Insert(i);
    EXPECT_ANY_THROW(h.Immertion(-1));
}
TEST(heap, Immertion_witn_more_index) {
    heap<int> h;
    for (int i = 0; i < 3; i++)
        h.Insert(i);
    EXPECT_ANY_THROW(h.Immertion(100));
}
TEST(heap, Immertion_change_size) {
    heap<int> h;
    h.Insert(5);
    h.Insert(84);
    h.Insert(2);
    int size1 = h.GetSize();
    h.Immertion(0);
    int size2 = h.GetSize();
    EXPECT_EQ(size1, size2);
}
TEST(heap, Emertion_with_neg_index) {
    heap<int> h;
    for (int i = 0; i < 3; i++)
        h.Insert(i);
    EXPECT_ANY_THROW(h.Emertion(-1));
}
TEST(heap, Emertion_with_more_index) {
    heap<int> h;
    for (int i = 0; i < 3; i++)
        h.Insert(i);
    EXPECT_ANY_THROW(h.Emertion(10));
}
TEST(heap, Emertion_cant_change_size) {
    heap<int> h;
    h.Insert(3);
    h.Insert(84);
    h.Insert(2);
    int size1 = h.GetSize();
    h.Emertion(0);
    int size2 = h.GetSize();
    EXPECT_EQ(size1, size2);
}

TEST(heap, erase_with_empty_heap) {
    heap<int> h;
    EXPECT_ANY_THROW(h.erase(0));
}
TEST(heap, erasemin_empty_heap) {
    heap<int> h;
    EXPECT_ANY_THROW(h.eraseMin());
}
TEST(heap, erase_changed_size) {
    heap<int> h;
    for (int i = 0; i < 10; i++)
        h.Insert(i);
    int size1 = h.GetSize();
    h.erase(0);
    h.erase(1);
    h.erase(4);
    int size2 = h.GetSize();
    EXPECT_EQ(size1 - 3, size2);
}
TEST(heap, eraseMin_changed_size) {
    heap<int> h;
    for (int i = 0; i < 10; i++)
        h.Insert(i);
    int size1 = h.GetSize();
    h.eraseMin();
    EXPECT_EQ(size1 - 1, h.GetSize());
}
TEST(heap, erase_with_neg_index) {
    heap<int> h;
    for (int i = 0; i < 10; i++)
        h.Insert(i);
    h.erase(0);
    EXPECT_ANY_THROW(h.erase(-4));
}
TEST(heap, erase_with_more_index) {
    heap<int> h;
    for (int i = 0; i < 10; i++)
        h.Insert(i);
    h.erase(0);
    EXPECT_ANY_THROW(h.erase(20));
}
TEST(heap, IsFull_works_correctly) {
    heap<int> h;
    for (int i = 0; i < 1000; i++)
        h.Insert(i);
    EXPECT_TRUE(h.Full());
}
TEST(heap, IsEmpty_works_correctly) {
    heap<int> h;
    EXPECT_TRUE(h.Empty());
}
