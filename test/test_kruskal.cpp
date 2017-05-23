#include <gtest/gtest.h>
#include "Kruskal_and_prime.h"
TEST(Kruscal, can_work_with_empty_graph) {
    vector<vector<pair<int, int>>> w;
    vector<pair<int, pair<int, int>>> res = Kruskal(w);
    EXPECT_TRUE(res.empty());
}

TEST(Kruskal, correct_work) {
    vector<pair<int, int>> v0 =
    { make_pair(1, 1), make_pair(3, 5), make_pair(2, 4) };
    vector<pair<int, int>> v1 = { make_pair(3, 2) };
    vector<pair<int, int>> v2 = { make_pair(3, 3) };
    vector<pair<int, int>> v3 = { make_pair(-1, -1) };
    vector<vector<pair<int, int>>> g = { v0, v1, v2, v3 };
    vector<pair<int, pair<int, int>>> res = Kruskal(g);
    vector<pair<int, pair<int, int>>> w1 =
    { make_pair(1, make_pair(0, 1)),
        make_pair(2, make_pair(1, 3)),
        make_pair(3, make_pair(2, 3)),
    };
    for (int i = 0; i < static_cast<int>(w1.size()); ++i)
        EXPECT_EQ(w1[i], res[i]);
}

TEST(Kruskal, check_forest) {
    vector<pair<int, int>> v0 = { make_pair(1, 10), make_pair(2, 8) };
    vector<pair<int, int>> v1 = { make_pair(-1, -1) };
    vector<pair<int, int>> v2 = { make_pair(-1, -1) };
    vector<pair<int, int>> v3 = { make_pair(4, 11), make_pair(5, 9) };
    vector<pair<int, int>> v4 = { make_pair(-1, -1) };
    vector<pair<int, int>> v5 = { make_pair(-1, -1) };
    vector<vector<pair<int, int>>> g = { v0, v1, v2, v3, v4, v5 };
    vector<pair<int, pair<int, int>>> res = Kruskal(g);
    vector<pair<int, pair<int, int>>> w1 =
    { make_pair(8, make_pair(0, 2)),
        make_pair(9, make_pair(3, 5)),
        make_pair(10, make_pair(0, 1)),
        make_pair(11, make_pair(3, 4)),
    };
    for (int i = 0; i < static_cast<int>(w1.size()); ++i)
        EXPECT_EQ(w1[i], res[i]);
}
