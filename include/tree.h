#ifndef INCLUDE_tree_H_
#define INCLUDE_tree_H_
#include <iostream>
struct CNode {
    CNode* left;
    CNode* right;
    int val;
    CNode() {}
    explicit CNode(int val_) {
        val = val_;
        left = nullptr;
        right = nullptr;
    }
};

CNode* Create(int* , int );
CNode** find(CNode**, int );

#endif  // INCLUDE_tree_H_
