#include "treefind.h"
#include <iostream>

int main() {
  CNode* t = CreateTree();
  PrintTree(&t);

  int num = 7;
  CNode** nt = find(&t, num);
  std::cout << "finded (" << num << "): " << nt << std::endl;
}
