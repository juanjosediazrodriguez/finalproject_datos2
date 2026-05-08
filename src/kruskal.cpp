#include "kruskal.hpp"
#include <algorithm>

struct DSU {
    std::vector<int> p, r;
    DSU(int n): p(n), r(n,0) { for (int i = 0; i < n; ++i) p[i] = i; }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) p[a] = b;
        else if (r[b] < r[a]) p[b] = a;
        else { p[b] = a; r[a]++; }
        return true;
    }
};

std::vector<Edge> kruskal_mst(int n, std::vector<Edge> edges, int& total_cost) {
    total_cost = 0;
    std::vector<Edge> res;
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){ return std::get<2>(a) < std::get<2>(b); });
    DSU dsu(n);
    for (auto &e : edges) {
        int u, v, w; std::tie(u, v, w) = e;
        if (dsu.unite(u, v)) {
            res.push_back(e);
            total_cost += w;
            if ((int)res.size() == n - 1) break;
        }
    }
    return res;
}
