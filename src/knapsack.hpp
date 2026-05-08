#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include <vector>
#include <utility>

// Devuelve {valor_optimo, indices_de_items_seleccionados}
std::pair<int,std::vector<int>> knapsack_dp(const std::vector<int>& weights, const std::vector<int>& values, int W);

#endif // KNAPSACK_HPP
