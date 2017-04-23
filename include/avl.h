#ifndef INCLUDE_AVL_H_
#define INCLUDE_AVL_H_
#include <stack>
#include <stdexcept>

template <typename T>
struct CNode {
  T val;
  int h;
  CNode* left;
  CNode* right;
  CNode* parent;

  explicit CNode(T a = 0, int b = 1, CNode* par = nullptr) : val(a), h(b),
    left(nullptr), right(nullptr), parent(par) {}
};

template <typename T>
class avltree {
  CNode<T>* head;

 private:
  CNode<T>* bal(CNode<T>*);
  CNode<T>* rightrot(CNode<T>*);
  CNode<T>* leftrot(CNode<T>*);
  int diff(CNode<T>*);
  void fixtree(CNode<T>*);

 public:
  explicit avltree(T a = T()) {
    if (a == T())
      head = nullptr;
    else
      head = new CNode<T>(a);
  }
  void ins(T);
  void delmin();
  T min();
  bool empty();
};

template <typename T>
bool avltree<T>::empty() {
  if (head)
    return false;
  else
    return true;
}

template <typename T>
void avltree<T>::fixtree(CNode<T>* a) {
  CNode<T>* par = a;
  int h1, h2;
  bool change = false;

  while (par != nullptr) {
    if ((diff(par) == 2) || diff(par) == -2) {
      if (par == head)
        change = true;
      par = bal(par);
      if (change)
        head = par;
    }
    if (par->left)
      h1 = par->left->h;
    else
      h1 = 0;
    if (par->right)
      h2 = par->right->h;
    else
      h2 = 0;

    par->h = (h1 > h2 ? h1 : h2) + 1;
    par = par->parent;
  }
}

template <typename T>
int avltree<T>::diff(CNode<T>* node) {
  if ((node->left == nullptr) && (node->right == nullptr))
    return 0;
  if (node->left == nullptr)
    return (-node->right->h);
  if (node->right == nullptr)
    return (node->left->h);
  return (node->left->h - node->right->h);
}

template <typename T>
void avltree<T>::ins(T a) {
  CNode<T>** tmp = &head;

  if (*tmp == nullptr) {
    head = new CNode<T>(a);
    return;
  }

  CNode<T>** tmp1;
  while (*tmp != nullptr) {
    if (a == (*tmp)->val)
      throw std::logic_error("eror");
    if (a < (*tmp)->val) {
      tmp1 = tmp;
      tmp = &((*tmp)->left);
    } else {
      tmp1 = tmp;
      tmp = &((*tmp)->right);
    }
  }
  *tmp = new CNode<T>(a, 1, *tmp1);

  fixtree(*tmp);
}

template <typename T>
CNode<T>* avltree<T>::bal(CNode<T>* node) {
  int dif = diff(node);

  if (dif == -2) {
    dif = diff(node->right);

    if (dif > 0)
      node->right = rightrot(node->right);
    node = leftrot(node);
  } else if (dif == 2) {
    dif = diff(node->left);

    if (dif < 0)
      node->left = leftrot(node->left);
    node = rightrot(node);
  }
  return node;
}

template <typename T>
CNode<T>* avltree<T>::rightrot(CNode<T>* node) {
  CNode<T>* tmp = node->left;
  node->left = tmp->right;
  if (node->left)
    node->left->parent = node;

  tmp->right = node;
  tmp->parent = node->parent;

  CNode<T>* par = tmp->parent;
  if (par) {
    if (par->left == node)
      tmp->parent->left = tmp;
    else
      tmp->parent->right = tmp;
  }

  node->parent = tmp;

  int h1, h2;
  if (node->left != 0) {
    h1 = node->left->h;
  } else {
    h1 = 0;
  }
  if (node->right != 0) {
    h2 = node->right->h;
  } else {
    h2 = 0;
  }

  node->h = (h1 > h2 ? h1 : h2) + 1;

  if (tmp->left)
    h1 = tmp->left->h;
  else
    h1 = 0;
  if (tmp->right)
    h2 = tmp->right->h;
  else
    h2 = 0;
  tmp->h = (h1 > h2 ? h1 : h2) + 1;

  return tmp;
}

template <typename T>
CNode<T>* avltree<T>::leftrot(CNode<T>* node) {
  CNode<T>* tmp = node->right;
  node->right = tmp->left;
  if (node->right)
    node->right->parent = node;

  tmp->left = node;
  tmp->parent = node->parent;

  CNode<T>* par = tmp->parent;
  if (par) {
    if (par->left == node)
      tmp->parent->left = tmp;
    else
      tmp->parent->right = tmp;
  }

  node->parent = tmp;

  int h1, h2;
  if (node->left != 0) {
    h1 = node->left->h;
  } else {
    h1 = 0;
  }
  if (node->right != 0) {
    h2 = node->right->h;
  } else {
    h2 = 0;
  }
  node->h = (h1 > h2 ? h1 : h2) + 1;

  if (tmp->left)
    h1 = tmp->left->h;
  else
    h1 = 0;
  if (tmp->right)
    h2 = tmp->right->h;
  else
    h2 = 0;
  tmp->h = (h1 > h2 ? h1 : h2) + 1;

  return tmp;
}

template <typename T>
void avltree<T>::delmin() {
  CNode<T>* tmp = head;

  if (!head)
    throw std::logic_error("Tree is empty!");

  while (tmp->left != nullptr) {
    tmp = tmp->left;
  }

  if (tmp->parent) {
    if (tmp->right)
      delete tmp->right;

    tmp = tmp->parent;
    delete tmp->left;
    tmp->left = nullptr;
    fixtree(tmp);
  } else {
    head = tmp->right;
    if (head)
      head->parent = nullptr;
    delete tmp;
  }
}

template <typename T>
T avltree<T>::min() {
  if (!head)
    throw std::logic_error("empty!");
  CNode<T>* tmp = head;

  while (tmp->left != nullptr) {
    tmp = tmp->left;
  }

  return tmp->val;
}
#endif  // INCLUDE_AVL_H_
