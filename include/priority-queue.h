#ifndef INCLUDE_PRIORITY_QUEUE_H_
#define INCLUDE_PRIORITY_QUEUE_H_
#include "three-heap.h"
template <class Type>
class Queue_on_heap {
    heap<Type>* h;
 public:
    Queue_on_heap();
    ~Queue_on_heap();
    int GetSize() { return h->GetSize(); }
    bool Full() { return h->Full(); }
    bool Empty() { return h->Empty(); }
    void Push(const Type& val);
    void Pop();
    Type Top();
    void Erase(const Type& val);
};

template<class Type>
Queue_on_heap<Type>::Queue_on_heap() {
    h = new heap<Type>();
}

template<class Type>
Queue_on_heap<Type>::~Queue_on_heap() {
    delete h;
}

template<class Type>
void Queue_on_heap<Type>::Push(const Type & val) {
    if (Full())
        throw logic_error("Heap is full");
    h->Insert(val);
}

template<class Type>
void Queue_on_heap<Type>::Pop() {
    if (Empty())
        throw logic_error("Heap is empty");
    h->eraseMin();
}

template<class Type>
Type Queue_on_heap<Type>::Top() {
    if (Empty())
        throw logic_error("Heap is empty");
    return (*h)[0];
}

template<class Type>
void Queue_on_heap<Type>::Erase(const Type& val) {
    for (int i = 0; i < h->GetSize(); ++i)
        if (h->val[i] == val)
            h->erase(i);
}
#endif  // INCLUDE_PRIORITY_QUEUE_H_
