#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <tuple>

using Edge = std::tuple<int,int,int>; // u, v, cost

struct Graph {
    int n;
    std::vector<Edge> edges;
};

// Construye grafo completo determinista a partir de los promedios mensuales por grupo.
Graph build_deterministic_graph(const std::vector<double>& groupMonthlyAvg);

#endif // GRAPH_HPP
