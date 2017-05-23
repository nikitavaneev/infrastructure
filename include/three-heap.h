#ifndef INCLUDE_THREE_HEAP_H_
#define INCLUDE_THREE_HEAP_H_
#include <stdexcept>
const int d_ = 3;
const int MAX_SIZE = 1000;
using std::logic_error;
template <class Type>
class heap {
    int size;
    int d;
 public:
    Type* val;
    heap();
    ~heap();
    int GetSize() { return size; }
    bool operator == (const heap<Type>& B);
    bool operator != (const heap<Type>& B);
    Type& operator[] (int i);
    bool Full() { return (size >= MAX_SIZE); }
    bool Empty() { return size == 0; }
    void erase(int i);
    void eraseMin();
    void Immertion(int i);
    void Emertion(int i);
    void Reduction(int i, const Type& con);
    void Swap(int i, int j);
    int MinChild(int i);
    void Insert(const Type& val_);
    void DoingHeaps();
};

template<class Type>
heap<Type>::heap() {
    d = d_;
    size = 0;
    val = new Type[MAX_SIZE];
}

template<class Type>
heap<Type>::~heap() {
    delete[] val;
}

template<class Type>
bool heap<Type>::operator==(const heap<Type>& B) {
    if (size != B.size)
        return false;
    for (int i = 0; i< size; ++i)
        if (val[i] != B.val[i])
            return false;
    return true;
}

template<class Type>
bool heap<Type>::operator!=(const heap<Type>& B) {
    return !((*this) == B);
}

template<class Type>
Type& heap<Type>::operator[](int i) {
    if (i< 0 || i >= size)
        throw logic_error("Overstepping");
    return val[i];
}

template<class Type>
void heap<Type>::erase(int i) {
    if (size == 0)
        throw logic_error("Heap is empty");
    if (i< 0 || i >= size)
        throw logic_error("Out of range");
    val[i] = val[size - 1];
    size--;
    if (size != 1) {
        if ((i != 0) && (val[i] < val[(i - 1) / d]))
            Emertion(i);
        else
            Immertion(i);
    }
}

template<class Type>
void heap<Type>::eraseMin() {
    if (size == 0)
        throw logic_error("Heap is empty");
    val[0] = val[size - 1];
    size--;
    if (size != 0)
        Immertion(0);
}

template<class Type>
int heap<Type>::MinChild(int i) {
    if (i< 0 || i >= size)
        throw logic_error("Overstepping");
    if (d*i + 1 >= size)
        return 0;
    int first = d*i + 1;
    Type min_val = val[first];
    int last = (i + 1) *d;
    if (last >= size)
        last = size - 1;
    for (int k = first + 1; k <= last; ++k)
        if (val[k] < min_val) {
            min_val = val[k];
            first = k;
        }
    return first;
}

template<class Type>
void heap<Type>::Immertion(int i) {
    if (i< 0 || i >= size)
        throw logic_error("Overstepping");
    int s = MinChild(i);
    while ((s != 0) && (val[i] > val[s])) {
        Swap(i, s);
        i = s;
        s = MinChild(i);
    }
}

template<class Type>
void heap<Type>::Emertion(int i) {
    if (i < 0 || i >= size)
        throw logic_error("Overstepping");
    int parent = (i - 1) / d;
    while ((i != 0) && (val[parent] > val[i])) {
        Swap(i, parent);
        i = parent;
        parent = (i - 1) / d;
    }
}

template<class Type>
void heap<Type>::Reduction(int i, const Type & con) {
    if (i< 0 || i >= size)
        throw logic_error("Overstepping");
    val[i] -= con;
    Emertion(i);
}

template<class Type>
void heap<Type>::Swap(int i, int j) {
    if ((i < 0) || (j < 0) || (i >= size) || (j >= size))
        throw logic_error("Overstepping");
    Type tmp = val[i];
    val[i] = val[j];
    val[j] = tmp;
}

template<class Type>
void heap<Type>::Insert(const Type& val_) {
    if (size >= MAX_SIZE)
        throw logic_error("Overstepping");
    val[size] = val_;
    size++;
    Emertion(size-1);
}

template<class Type>
void heap<Type>::DoingHeaps() {
    if (size > 0) {
        for (int i = (size - 1) / d; size > 0;)
            Immertion(i);
    }
}

#endif  // INCLUDE_THREE_HEAP_H_
