#include "algoritm.h"
#include <stdio.h>
#include <vector>
#include <limits.h>

using std::vector;
using std::pair;

int main() {
  printf("path to file: ");
  char path[150];
  scanf("%s", path);
  FILE* fp = fopen(path, "r");

  if (fp == 0) {
    printf("Error open file");
    return 0;
  }
  vector< vector < pair<int, int> > > graph;

  int s = 0;
  int ch = 0;
  int i = 0;
  pair<int, int>* a = new pair<int, int>;
  vector<pair<int, int>>* v = new vector<pair<int, int>>;

  while ((ch = fgetc(fp)) != EOF) {
    if (ch != ' ') {
      if (ch == '\n') {
        graph.push_back(*v);
        v = new vector<pair<int, int>>;
        i++;
      } else {
        if (s == 0) {
          a->second = ch - 48;
          s = 1;
        } else {
          a->first = ch - 48;
          s = 0;
          v->push_back(*a);
          a = new pair<int, int>;
        }
      }
    }
  }
  fclose(fp);
  int st = 1;
  while (st == 1) {
    st = 2;
    printf("1 - Heap\n2 - AVL-tree\n");
    int qu;
    scanf("%d", &qu);
    printf("First vertex: ");
    int fv;
    scanf("%d", &fv);

    vector<int> minw;
    switch (qu) {
    case 1:
      minw = Dijkstra_Heap(graph, fv);
      break;
    case 2:
      minw = Dijkstra_Tree(graph, fv);
    }

    printf("Min ways:\n");
    s = minw.size();
    for (int i = 0; i < s; i++) {
        printf("%d: %d\n", i, minw[i]);
    }

  }
}