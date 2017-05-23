#include <gtest/gtest.h>
#include "priority-queue.h"

TEST(QUEUEHeap, create_queue) {
    EXPECT_NO_THROW(Queue_on_heap<int> a);
}
TEST(QUEUEHeap, check_empty) {
    Queue_on_heap<int> a;
    EXPECT_TRUE(a.Empty());
}
TEST(QUEUEHeap, Size_of_empty) {
    Queue_on_heap<int> a;
    EXPECT_EQ(0, a.GetSize());
}

TEST(QUEUEHeap, Can_pop) {
    Queue_on_heap<int> a;
    for (int i = 0; i < 3; ++i)
        a.Push(i);
    EXPECT_NO_THROW(a.Pop());
}
TEST(QUEUEHeap, pop_with_empty) {
    Queue_on_heap<int> a;
    EXPECT_ANY_THROW(a.Pop());
}
TEST(QUEUEHeap, Pop_size) {
    Queue_on_heap<int> a;
    for (int i = 0; i < 3; ++i)
        a.Push(i);
    int size1 = a.GetSize();
    a.Pop();
    int size2 = a.GetSize();
    EXPECT_EQ(size1 - 1, size2);
}
TEST(QUEUEHeap, check_Top) {
    Queue_on_heap<int> a;
    for (int i = 0; i < 3; ++i)
        a.Push(i);
    EXPECT_EQ(0, a.Top());
}
TEST(QUEUEHeap, Top_with_empty_queue) {
    Queue_on_heap<int> a;
    EXPECT_ANY_THROW(a.Top());
}
TEST(QUEUEHeap, push) {
    Queue_on_heap<int> a;
    EXPECT_NO_THROW(a.Push(7));
}
TEST(QUEUEHeap, push_size) {
    Queue_on_heap<int> a;
    int size1 = a.GetSize();
    a.Push(1);
    int size2 = a.GetSize();
    EXPECT_EQ(size1 + 1, size2);
}
TEST(QUEUEHeap, check_Full) {
    Queue_on_heap<int> a;
    for (int i = 0; i < 1000; ++i)
        a.Push(i);
    EXPECT_TRUE(a.Full());
}
TEST(QUEUEHeap, _push_to_full_) {
    Queue_on_heap<int> a;
    for (int i = 0; i < 1000; ++i)
        a.Push(i);
    EXPECT_ANY_THROW(a.Push(100345));
}

TEST(QUEUEonHeap, Push_update_queue) {
    Queue_on_heap<int> a;
    for (int i = 1; i < 10; ++i)
        a.Push(i);
    EXPECT_EQ(1, a.Top());
    a.Push(0);
    EXPECT_EQ(0, a.Top());
}
