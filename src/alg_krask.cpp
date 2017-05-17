#include "add.h"


vector<vector<int>> alg_krask(vector<vector<int>> graph) {
  if (graph.size() != 0) {
    vector<vector<int>> ostov;
    for (unsigned int i = 0; i < graph.size(); i++) {
      vector<int>  str(graph.size() - i);
      for (unsigned int j = 0; j < graph.size() - i; ++j)
        str[j] = 0;
      ostov.push_back(str);
    }
    Union_Find a(graph.size());
    vector <tuple<int, int, int >> edges;

    for (unsigned int i = 0; i < graph.size(); ++i) {
      for (unsigned int j = 0; j < graph[i].size(); ++j) {
        if (graph[i][j] != MAX && graph[i][j] > 0) {
          edges.push_back(std::make_tuple(graph[i][j], i, i + j));
        }
      }
    }
    sort(edges.begin(), edges.end());
    unsigned int n = 0;
    while (n < graph.size() - 1) {
      tuple<int, int, int> current;
      current = *(edges.begin());
      edges.erase(edges.begin());
      if (a.Find_set(std::get<1>(current)) != a.Find_set(std::get<2>(current))) {
        a.Union_set(a.Find_set(get<1>(current)), a.Find_set(std::get<2>(current)));
        int e = std::get<1>(current);
        int b = std::get<2>(current);
        int c = std::get<0>(current);
        ostov[e][b - e] = c;
        n++;
      }
    }
    return ostov;
  } else {
    throw 1;
  }
}


