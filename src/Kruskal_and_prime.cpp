#include "Kruskal_and_prime.h"
#include "priority-queue.h"
#include <stdio.h>
#include "find_and_union.h"
using std::min;
using std::max;
vector<pair<int, pair<int, int>>> Prime(vector<vector<int>> w, int st) {
    int n = w.size();
    vector<pair<int, pair<int, int>>> res;
    if (n == 0)
        return res;
    vector<int> min_e(n, MAX), sel_e(n, -1);
    min_e[st] = 0;
    Queue_on_heap<pair<int, int>> q;
    vector<bool> used(n + 1, false);
    q.Push(make_pair(min_e[st], st));
    for (int i = 0; i < n; ++i) {
        if (q.Empty())
            throw logic_error("No MST");
        int vertex = q.Top().second;
        q.Pop();
        used[vertex] = true;
        if (sel_e[vertex] != -1) {
            int mi = min(sel_e[vertex], vertex);
            int ma = max(sel_e[vertex], vertex);
            res.push_back(make_pair(min_e[vertex], make_pair(mi, ma)));
        }
        for (size_t j = 0; j < w[vertex].size(); ++j) {
            int to = j;
            int cost = w[vertex][j];
            if (cost < min_e[to] && !used[to]) {
                q.Erase(make_pair(min_e[to], to));
                min_e[to] = cost;
                sel_e[to] = vertex;
                q.Push(make_pair(min_e[to], to));
            }
        }
    }
    return res;
}


vector<pair<int, pair<int, int>>> Kruskal(vector<vector<pair<int, int>>> w) {
    int n = w.size();
    vector<pair<int, pair<int, int>>> res;
    vector<int> parent(n);
    vector<pair<int, int>>::iterator it;
    for (int i = 0; i < n; ++i)
        parent[i] = i;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < n; ++i)
        for (it = w[i].begin(); it != w[i].end(); ++it) {
            if ((*it).second == -1)
                continue;
            edges.push_back(make_pair((*it).second, make_pair(i, (*it).first)));
        }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
        int vertex1 = edges[i].second.first;
        int vertex2 = edges[i].second.second;
        int x = Find(parent, vertex1);
        int y = Find(parent, vertex2);
        if (x != y) {
            res.push_back(edges[i]);
            Union(&parent, vertex1, vertex2);
        }
    }
    return res;
}
