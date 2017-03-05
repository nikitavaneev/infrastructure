#include "add.h"
#include <iostream>
int main() {
    CNode* tree1 = 0;
    PrintTree(&tree1);
    CNode* tree = new CNode(5);
    tree->left = new CNode(6);
    tree->right = new CNode(4);
    tree->right->right = new CNode(3);
    PrintTree(&tree);
}

