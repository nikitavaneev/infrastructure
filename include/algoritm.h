#ifndef INCLUDE_ALGORITM_H_
#define INCLUDE_ALGORITM_H_
#include <vector>
#include <utility>

using std::vector;
using std::pair;

vector<int> Dijkstra_Heap(vector< vector< pair<int, int> > > ls, int a);
vector<int> Dijkstra_Tree(vector< vector< pair<int, int> > > ls, int a);

#endif  // INCLUDE_ALGORITM_H_
