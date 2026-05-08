#include "graph.hpp"
#include <cmath>

Graph build_deterministic_graph(const std::vector<double>& groupMonthlyAvg) {
    Graph g;
    g.n = (int)groupMonthlyAvg.size();
    for (int u = 0; u < g.n; ++u) {
        for (int v = u + 1; v < g.n; ++v) {
            double sum = groupMonthlyAvg[u] + groupMonthlyAvg[v];
            int cost = (int)std::floor(sum);
            g.edges.emplace_back(u, v, cost);
        }
    }
    return g;
}
