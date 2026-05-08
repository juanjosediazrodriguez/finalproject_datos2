#include "binary_search.hpp"

static int bs_rec(const std::vector<Solicitud>& a, int l, int r, int k) {
    if (l >= r) return -1;
    int m = (l + r) / 2;
    if (a[m].tenure >= k) {
        int left = bs_rec(a, l, m, k);
        return (left != -1) ? left : m;
    } else {
        return bs_rec(a, m + 1, r, k);
    }
}

int binary_search_first_ge(const std::vector<Solicitud>& a, int k) {
    if (a.empty()) return -1;
    return bs_rec(a, 0, (int)a.size(), k);
}
