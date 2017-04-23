#include <vector>
#include <utility>
#include "avl.h"
#include "pr_queue_t.h"
#include <limits.h>

using std::vector;
using std::pair;


vector<int> Dijkstra_Heap(vector< vector< pair<int, int> > > ls, int a) {
  if (a >= static_cast<int>(ls.size())) {
    throw std::logic_error("Vertex!");
  }
  pr_queue_h <pair <int, int> > T;
  bool *aw = new bool[ls.size()];
  for (unsigned int i = 0; i < ls.size(); i++)
    aw[i] = true;

  vector<int> ret(ls.size(), INT_MAX);
  auto t = ls[a];

  for (auto it = t.begin(); it != t.end(); it++) {
    T.add(*it);
    ret[it->second] = it->first;
  }

  ret[a] = 0;
  aw[a] = false;
  while (!T.empty()) {
    int vs = T.min().second;
    T.delmin();
    if (aw[vs] != false) {
      aw[vs] = false;
      t = ls[vs];

      for (auto it = t.begin(); it != t.end(); it++) {
        if (it->first + ret[vs] < ret[it->second])
          ret[it->second] = it->first + ret[vs];
        T.add(std::make_pair(it->first + ret[vs], it->second));
      }
    }
  }
  return ret;
}

vector<int> Dijkstra_Tree(vector< vector< pair<int, int> > > ls, int a) {
  if (a >= static_cast<int>(ls.size())) {
    throw std::logic_error("Vertex!");
  }
  pr_queue_t <pair <int, int> > T;
  bool *aw = new bool[ls.size()];
  for (unsigned int i = 0; i < ls.size(); i++)
    aw[i] = true;

  vector<int> ret(ls.size(), INT_MAX);
  auto t = ls[a];

  for (auto it = t.begin(); it != t.end(); it++) {
    T.ins(*it);
    ret[it->second] = it->first;
  }

  ret[a] = 0;
  aw[a] = false;
  while (!T.empty()) {
    int vs = T.min().second;
    T.delmin();
    if (aw[vs] != false) {
      aw[vs] = false;
      t = ls[vs];

      for (auto it = t.begin(); it != t.end(); it++) {
        if (it->first + ret[vs] < ret[it->second])
          ret[it->second] = it->first + ret[vs];
        T.ins(std::make_pair(it->first + ret[vs], it->second));
      }
    }
  }
  return ret;
}
