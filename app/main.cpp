#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Kruskal_and_prime.h"
#include "vizual.h"
int main() {
    std::cout << "Prime\n";
    std::cout << "Enter way to the graph:";
    char str[300];
    std::cin >> str;
    std::cout << "\n";
    vector<vector<int>> w = Read_Graph_Matrix(str);
    std::cout << "\n";
    vector<pair<int, pair<int, int>>> res1 = Prime(w, 1);
    Write_To_Prim_Gv(w, res1);
    std::cout << "Kruskal\n";
    std::cout << "Enter way to the graph:";
    char str2[300];
    std::cin >> str2;
    std::cout << "\n";
    vector<vector<pair<int, int>>> w2 = Read_Graph_List(str2);
    std::cout << "\n";
    vector<pair<int, pair<int, int>>> res2 = Kruskal(w2);
    Write_To_Kruskal_Gv(w2, res2);
    std::cout << "\n";
    return 0;
}
