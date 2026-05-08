#include "knapsack.hpp"
#include <vector>
#include <algorithm>

std::pair<int,std::vector<int>> knapsack_dp(const std::vector<int>& weights, const std::vector<int>& values, int W) {
    int n = (int)weights.size();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(W+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            dp[i][w] = dp[i-1][w];
            if (weights[i-1] <= w) dp[i][w] = std::max(dp[i][w], dp[i-1][w-weights[i-1]] + values[i-1]);
        }
    }
    int best = dp[n][W];
    std::vector<int> taken;
    int w = W;
    for (int i = n; i >= 1; --i) {
        if (dp[i][w] != dp[i-1][w]) {
            taken.push_back(i-1);
            w -= weights[i-1];
        }
    }
    std::reverse(taken.begin(), taken.end());
    return {best, taken};
}
