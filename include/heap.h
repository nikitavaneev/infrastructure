#ifndef INCLUDE_HEAP_H_
#define INCLUDE_HEAP_H_
#include <vector>
#include <stdexcept>

using std::vector;
using std::pair;

template <typename T>
class heap {
  vector<T> head;
  void shift_up(int a);
  void shift_down(int b);

 public:
  T min();
  void add(T);
  void delmin();
  bool empty();
};

template <typename T>
bool heap<T>::empty() {
  return head.empty();
}

template <typename T>
void heap<T>::add(T pr) {
  head.push_back(pr);
  shift_up(head.size() - 1);
}

template <typename T>
T heap<T>::min() {
  if (!head.empty())
    return head[0];
  else
    throw std::logic_error("empty!");
}

template <typename T>
void heap<T>::delmin() {
  if (!head.empty()) {
    head[0] = head[head.size() - 1];
    head.erase(head.end() - 1);
    shift_down(0);
  } else {
    throw std::logic_error("empty!");
  }
}

template <typename T>
void heap<T>::shift_up(int pos) {
  int pospar = (pos - 1) / 3;
  while (head[pospar] > head[pos]) {
    std::swap(head[pospar], head[pos]);

    pos = pospar;
    pospar = (pospar - 1) / 3;
  }
}

template <typename T>
void heap<T>::shift_down(int pos) {
  int end = head.size();
  while (3*pos + 1 < end) {
    T min = head[3 * pos + 1];
    int posmin = 3 * pos + 1;
    for (int i = 2; (i < 4), (3 * pos + i) < end; i++) {
      if (head[3 * pos + i] < min) {
        min = head[3 * pos + i];
        posmin = 3 * pos + i;
      }
    }
    std::swap(head[pos], head[posmin]);
    pos = posmin;
  }
}
#endif  // INCLUDE_HEAP_H_
