#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

#include "graph.hpp"
#include <vector>

using Edge = std::tuple<int,int,int>;

// Devuelve la lista de aristas del MST y escribe el costo total en `total_cost`.
std::vector<Edge> kruskal_mst(int n, std::vector<Edge> edges, int& total_cost);

#endif // KRUSKAL_HPP
