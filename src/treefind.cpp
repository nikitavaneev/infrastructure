#include "treefind.h"
#include <queue>
#include <iostream>

CNode::CNode(int v = 0) {
  val = v;
  left = 0;
  right = 0;
}

CNode* CreateTree() {
  CNode* t = new CNode(4);
  t->left = new CNode(2);
  t->right = new CNode(6);
  t->right->left = new CNode(5);
  t->right->right = new CNode(7);
  t->left->left = new CNode(1);
  t->left->right = new CNode(3);

  return t;
}

void PrintTree(CNode** root) {
  std::queue<CNode**> q;
  q.push(root);
  CNode** tmp;

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if ((*tmp)->left)
      q.push(&(*tmp)->left);
    if ((*tmp)->right)
      q.push(&(*tmp)->right);

    std::cout << tmp << std::endl << "value:" << (*tmp)->val << std::endl <<
      "&left: " << &(*tmp)->left << std::endl << "&right: " << &(*tmp)->right
      << std::endl << std::endl;
  }
}

CNode** find(CNode** root1, int v) {
  CNode** root = root1;
  while (*root) {
    if ((*root)->val == v) {
      return root;
    } else if ((*root)->val < v) {
      root = &(*root)->right;
    } else {
      root = &(*root)->left;
    }
  }
  return root;
}


