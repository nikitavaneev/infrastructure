#include "dijkstra.h"
std::vector<int> dijkstra(std::vector <std::vector
    <std::pair <int, int > > > graph, int s) {
    if (graph.size() == 0) {
        throw std::logic_error("size = 0");
    }
    std::vector<int> d(graph.size(), MAX);
    d[s] = 0;
    std::set<std::pair<int, int> > unused;
    unused.insert(std::make_pair(0, s));
    while (!unused.empty()) {
        int i = unused.begin()->second;
        unused.erase(unused.begin());
        for (auto temp : graph[i]) {
            int j = temp.first;
            int wt = temp.second;
            if (d[i] + wt < d[j]) {
                unused.erase(std::make_pair(d[j], j));
                d[j] = d[i] + wt;
                unused.insert(std::make_pair(d[j], j));
                }
        }
    }
    return d;
}
