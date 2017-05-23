#ifndef INCLUDE_KRUSKAL_AND_PRIME_H_
#define INCLUDE_KRUSKAL_AND_PRIME_H_
#include <algorithm>
#include <vector>
#include <utility>
using std::vector;
using std::pair;
using std::make_pair;
const int MAX = 100000000;
vector<pair<int, pair<int, int>>> Kruskal(vector<vector<pair<int, int>>> g);
vector<pair<int, pair<int, int>>> Prime(vector<vector<int>> g, int st);
#endif  // INCLUDE_KRUSKAL_AND_PRIME_H_
