#include "tree.h"
#include <iostream>
#include <queue>

int main() {
    int n = 5;
    int mass[5] = { 1, 2, 3, 4, 5 };
    CNode* res = Create(mass, n);
    std::queue<CNode*> q;
    q.push(res);
    while (!q.empty()) {
        int size = q.size();
        CNode* tmp;
        for (int i = 0; i < size; i++) {
            tmp = q.front();
            q.pop();
            std::cout << tmp->val;
            if (tmp->left != 0)
                q.push(tmp->left);
            if (tmp->right != 0)
                q.push(tmp->right);
        }
        std::cout << std::endl;
    }
}


