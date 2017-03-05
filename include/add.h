#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_
#include<iostream>
#include<queue>
using std::cout;
using std::endl;
struct CNode {
    int value;
    CNode* left;
    CNode* right;
    explicit CNode(int v) { value = v; left = 0; right = 0; }
};
CNode* find(CNode* root, int v);
void PrintTree(CNode** root);
#endif  // INCLUDE_ADD_H_
