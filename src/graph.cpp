#include "graph.hpp"
#include <cmath>

std::vector<double> compute_group_monthly_avg(const std::vector<Solicitud>& solicitudes, int group_count) {
    std::vector<double> sum(group_count, 0.0);
    std::vector<int> count(group_count, 0);

    for (size_t i = 0; i < solicitudes.size(); ++i) {
        int group = static_cast<int>(i % group_count);
        sum[group] += solicitudes[i].monthlyCharges;
        count[group] += 1;
    }

    std::vector<double> avg(group_count, 0.0);
    for (int g = 0; g < group_count; ++g) {
        if (count[g] == 0) continue;
        double value = sum[g] / count[g];
        avg[g] = std::round(value * 100.0) / 100.0;
    }
    return avg;
}

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
