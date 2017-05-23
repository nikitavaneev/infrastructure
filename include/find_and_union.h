#ifndef INCLUDE_FIND_AND_UNION_H_
#define INCLUDE_FIND_AND_UNION_H_
#include "Kruskal_and_prime.h"
int Find(vector<int> parent, int p) {
    int res = p;
    while (parent[res] != res) {
        res = parent[res];
    }
    return res;
}
void Union(vector<int>* parent, int p, int q) {
    int x = Find(*parent, p);
    int y = Find(*parent, q);
    (*parent)[x] = y;
}
#endif  // INCLUDE_FIND_AND_UNION_H_
