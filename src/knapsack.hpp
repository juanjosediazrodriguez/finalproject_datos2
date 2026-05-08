#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include <vector>
#include <utility>

// devuelvo valor optimo e indice de items 
std::pair<int,std::vector<int>> knapsack_dp(const std::vector<int>& weights, const std::vector<int>& values, int W);

#endif 
