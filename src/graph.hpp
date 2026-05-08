#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <tuple>
#include "parser.hpp"

using Edge = std::tuple<int,int,int>; // u, v, cost

struct Graph {
    int n;
    std::vector<Edge> edges;
};

// calcula promedio de monthly charges
std::vector<double> compute_group_monthly_avg(const std::vector<Solicitud>& solicitudes, int group_count = 20);

// construye grafo
Graph build_deterministic_graph(const std::vector<double>& groupMonthlyAvg);

#endif
