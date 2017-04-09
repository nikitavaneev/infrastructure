#include <gtest/gtest.h>
#include "dijkstra.h"

TEST(Dijkstra, null) {
    std::vector <std::vector <std::pair <int, int > > > w;
    ASSERT_ANY_THROW(dijkstra(w, 0));
}

TEST(Dijkstra, One) {
    std::vector <std::vector <std::pair <int, int > > > w(1);
    std::vector<int> result = dijkstra(w, 0);
    EXPECT_EQ(result[0], 0);
}

TEST(Dijkstra, graph) {
    std::vector <std::vector <std::pair <int, int > > > w(5);
    w[0].push_back(std::make_pair(1, 2));
    w[0].push_back(std::make_pair(2, 3));
    w[0].push_back(std::make_pair(3, 4));
    w[1].push_back(std::make_pair(4, 5));
    w[2].push_back(std::make_pair(4, 6));
    w[3].push_back(std::make_pair(4, 7));
    std::vector<int> result = dijkstra(w, 0);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 3);
    EXPECT_EQ(result[3], 4);
    EXPECT_EQ(result[4], 7);
}

TEST(Dijkstra, Loops) {
    std::vector <std::vector <std::pair <int, int > > > w(5);
    w[0].push_back(std::make_pair(1, 2));
    w[0].push_back(std::make_pair(0, 0));
    w[0].push_back(std::make_pair(2, 3));
    w[0].push_back(std::make_pair(3, 4));
    w[1].push_back(std::make_pair(4, 5));
    w[1].push_back(std::make_pair(1, 0));
    w[2].push_back(std::make_pair(4, 6));
    w[2].push_back(std::make_pair(2, 0));
    w[3].push_back(std::make_pair(4, 7));
    w[3].push_back(std::make_pair(3, 0));
    std::vector<int> result = dijkstra(w, 0);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 3);
    EXPECT_EQ(result[3], 4);
    EXPECT_EQ(result[4], 7);
}
