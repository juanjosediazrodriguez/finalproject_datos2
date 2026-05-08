#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

#include "graph.hpp"
#include <vector>

using Edge = std::tuple<int,int,int>;

// devuelve aristas del MST y escribe el costo total 
std::vector<Edge> kruskal_mst(int n, std::vector<Edge> edges, int& total_cost);

#endif 
