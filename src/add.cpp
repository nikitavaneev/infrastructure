#include<add.h>
CNode* find(CNode* root, int v) {
	while (root) {
		if ((root->value > v) && (root->right != 0)) {
			root = root->right;
		}
		else if ((root->value < v) && (root->left != 0)) {
			root = root->left;
		}
		else {
			return root;
		}
	}
	return root;
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

		std::cout << tmp << std::endl << "value:" << (*tmp)->value << std::endl <<
			"&left: " << &(*tmp)->left << std::endl << "&right: " << &(*tmp)->right
			<< std::endl << std::endl;
	}
}