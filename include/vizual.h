#ifndef INCLUDE_VIZUAL_H_
#define INCLUDE_VIZUAL_H_
#include "Kruskal_and_prime.h"
#include <stdio.h>
#include <stdexcept>
using std::logic_error;
vector<vector<pair<int, int>>> Read_Graph_List(char* name) {
    FILE* g = fopen(name, "r");
    if (g == 0)
        throw std::logic_error("Error! The way is not correct");
    vector<vector<pair<int, int>>> graph;
    int ch = 0;
    vector<pair<int, int>>* v = new vector<pair<int, int>>;
    ch = fgetc(g);
    while (ch != ':')
        ch = fgetc(g);
    while ((ch = fgetc(g)) != EOF) {
        if (ch != ' ') {
            if (ch == '\n') {
                if ((*v).size() == 0)
                    (*v).push_back(make_pair(-1, -1));
                graph.push_back(*v);
                v = new vector<pair<int, int>>;
                while (ch != ':')
                    ch = fgetc(g);
            } else {
                int vertex = ch;
                ch = fgetc(g);
                if ((ch = fgetc(g)) == '\n')
                    throw std::logic_error("Error! Incorrect list!");
                (*v).push_back(make_pair(vertex - 48, ch - 48));
            }
        }
    }
    graph.push_back(*v);
    fclose(g);
    return graph;
}

vector<vector<int>> Read_Graph_Matrix(char* name) {
    FILE* g = fopen(name, "r");
    if (g == 0)
        throw std::logic_error("Error! The way is not correct");
    vector<vector<int>> w;
    int ch = 0;
    vector<int>* v = new vector<int>;
    while ((ch = fgetc(g)) != EOF) {
        if (ch != ' ') {
            if (ch == '\n') {
                w.push_back(*v);
                v = new vector<int>;
            } else {
                if (ch == '-')
                    v->push_back(MAX);
                else
                    v->push_back(ch - 48);
            }
        }
    }
    w.push_back(*v);
    fclose(g);
    return w;
}

void Write_To_Kruskal_Gv(vector<vector<pair<int, int>>> graph,
    vector<pair<int, pair<int, int>>> res) {
    FILE* g = fopen("Kruskal.txt", "w");
    if (g == 0)
        throw std::logic_error("Error! Can`t open the file!");
    fputs("graph { \nedge[color = \"#FF0000\"]\n", g);
    int n = res.size();
    for (int i = 0; i < n; ++i) {
        int vertex1 = res[i].second.first;
        int vertex2 = res[i].second.second;
        int weight = res[i].first;
        fputc(vertex1 + 48, g);
        fputs("--", g);
        fputc(vertex2 + 48, g);
        fputs("[style = \"bold\", label=\"", g);
        fputc(weight + 48, g);
        fputs("\"]\n", g);
        vector<pair<int, int>>::iterator it = graph[vertex1].begin();
        for (int i = 0; i < static_cast<int>(graph[vertex1].size()); ++i) {
            if (graph[vertex1][i] == (make_pair(vertex2, weight))) {
                graph[vertex1].erase(it);
                continue;
            }
            ++it;
        }
    }
    for (int i = 0; i < static_cast<int>(graph.size()); ++i)
        for (int j = 0; j < static_cast<int>(graph[i].size()); ++i) {
            int vertex1 = i;
            int vertex2 = graph[i][j].first;
            int weight = graph[i][j].second;;
            fputc(vertex1 + 48, g);
            fputs("--", g);
            fputc(vertex2 + 48, g);
            fputs("[color = black, label=\"", g);
            fputc(weight + 48, g);
            fputs("\"]\n", g);
            fputc(vertex1 + 48, g);
            fputs(" [shape = \"rect\", color = black]\n", g);
            fputc(vertex2 + 48, g);
            fputs(" [shape = \"rect\", color = black]\n", g);
        }
    fputs("}\n", g);
    fclose(g);
}
void Write_To_Prim_Gv(vector<vector<int>> graph, vector<pair<int, pair<int, int>>> res) {
    FILE* g = fopen("Prime.txt", "w");
    if (g == 0)
        throw std::logic_error("Error! The way is not correct!");
    fputs("graph { \nedge[color = \"#FF0000\"]\n", g);
    int n = res.size();
    for (int i = 0; i < n; ++i) {
        int vertex1 = res[i].second.first;
        int vertex2 = res[i].second.second;
        int weight = res[i].first;
        fputc(vertex1 + 48, g);
        fputs("--", g);
        fputc(vertex2 + 48, g);
        fputs("[style = \"bold\", label=\"", g);
        fputc(weight + 48, g);
        fputs("\"]\n", g);
        graph[vertex1][vertex2] = MAX;
        graph[vertex2][vertex1] = MAX;
    }
    for (int i = 0; i < static_cast<int>(graph.size()); ++i)
        for (int j = 0; j < static_cast<int>(graph[i].size()); ++j)
            if ((graph[i][j] != MAX) && (i != j)) {
                fputc(i + 48, g);
                fputs("--", g);
                fputc(j + 48, g);
                fputs("[color = black, label=\"", g);
                fputc(graph[i][j] + 48, g);
                fputs("\"]\n", g);
                fputc(i + 48, g);
                fputs(" [shape = \"rect\", color = black]\n", g);
                fputc(j + 48, g);
                fputs(" [shape = \"rect\", color = black]\n", g);
                graph[j][i] = MAX;
            }

    fputs("}\n", g);
    fclose(g);
}

#endif  // INCLUDE_VIZUAL_H_
