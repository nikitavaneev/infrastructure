#ifndef INCLUDE_TREEFIND_H_
#define INCLUDE_TREEFIND_H_

struct CNode {
  int val;
  CNode* left, *right;
  explicit CNode(int v);
};

void PrintTree(CNode** root);

CNode* CreateTree();

CNode** find(CNode** root, int v);

#endif  // INCLUDE_TREEFIND_H_
