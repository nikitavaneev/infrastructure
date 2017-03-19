#include "tree.h"
#include <queue>

CNode** find(CNode**root, int a) {
    while (*root) {
        if ((*root)->val == a) {
            return root;
        }
        else {
           if ((*root)->val < a) {
               root = &(*root)->right;
            }
            else {
               root = &(*root)->left;
            }
        }
    }
    return root;
}
CNode* Create(int * mass, int n) {
    CNode* root = nullptr;
    int a = 0;
    int b = n - 1;
    int mid;
    std::queue<int> q;
    q.push(a);
    q.push(b);
    while (!q.empty()) {
        a = q.front();
        q.pop();
        b = q.front();
        q.pop();
        if (b <a) {
            continue;
        }
        mid = (a + b) / 2;
        CNode** tmp = find(&root, mass[mid]);
        *tmp = new CNode(mass[mid]);
        q.push(a);
        q.push(mid - 1);
        q.push(mid + 1);
        q.push(b);
    }
    return root;
}
