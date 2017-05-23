#include <gtest/gtest.h>
#include "Kruskal_and_prime.h"
TEST(Prime, check_empty) {
    vector<vector<int>> w;
    vector<pair<int, pair<int, int>>> res = Prime(w, 0);
    EXPECT_TRUE(res.empty());
}
TEST(Prime, check_work) {
    vector<vector<int>> w =
    { { 0, 9, MAX, MAX, MAX },
    { 9, 0, 5, MAX, MAX },
    { MAX, 5, 0, 8, 3 },
    { MAX, MAX, 8, 0, MAX },
    { MAX, MAX, 3, MAX, 8 } };
    vector<pair<int, pair<int, int>>> res = Prime(w, 0);
    vector<pair<int, pair<int, int>>> w2 = {
        make_pair(9, make_pair(0, 1)),
        make_pair(5, make_pair(1, 2)),
        make_pair(3, make_pair(2, 4)),
        make_pair(8, make_pair(2, 3))
    };
    for (int i = 0; i < static_cast<int>(w2.size()); ++i)
        EXPECT_EQ(w2[i], res[i]);
}
TEST(Prime, Correct_work) {
    vector<vector<int>> w =
    { { 0, 5, MAX, 2, 7 },
    { 5, 0, 8, MAX, 1 },
    { MAX, 8, 0, 5, 8 },
    { 2, MAX, 5, 0, 4 },
    { 7, 1, 8, 4, 0 } };
    vector<pair<int, pair<int, int>>> res = Prime(w, 0);
    vector<pair<int, pair<int, int>>> w1 =
    { make_pair(2, make_pair(0, 3)),
        make_pair(4, make_pair(3, 4)),
        make_pair(1, make_pair(1, 4)),
        make_pair(5, make_pair(2, 3)),
    };
    for (int i = 0; i < static_cast<int>(w1.size()); ++i)
        EXPECT_EQ(w1[i], res[i]);
}

TEST(Prime, check_forest) {
    vector<vector<int>> w =
    { { 0, MAX, 10, MAX, 4 },
    { MAX, 0, MAX, 5, MAX },
    { 1, MAX, 0, MAX, 6 },
    { MAX, 4, MAX, 0, MAX },
    { 10, MAX, 3, MAX, 0 } };
    EXPECT_ANY_THROW(Prime(w, 0));
}
