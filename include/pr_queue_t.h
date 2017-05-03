#ifndef INCLUDE_PR_QUEUE_T_H_
#define INCLUDE_PR_QUEUE_T_H_
#include "avl.h"
#include "heap.h"

template <typename T>
class pr_queue_t : public avltree<T> {
};

template <typename T>
class pr_queue_h : public heap<T> {
};

#endif  // INCLUDE_PR_QUEUE_T_H_
