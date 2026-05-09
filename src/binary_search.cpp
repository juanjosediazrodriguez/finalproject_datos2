#include "binary_search.hpp"

// Array is sorted DESCENDING. Find rightmost index where tenure >= k
// (last element that still qualifies, i.e. the boundary of the high-priority range).
static int bs_rec(const std::vector<Solicitud>& a, int l, int r, int k) {
    if (l >= r) return -1;
    int m = (l + r) / 2;
    if (a[m].tenure >= k) {
        // m qualifies; check right half for a later qualifying index
        int right = bs_rec(a, m + 1, r, k);
        return (right != -1) ? right : m;
    } else {
        // a[m] < k; right half has even smaller values — search left half
        return bs_rec(a, l, m, k);
    }
}

int binary_search_first_ge(const std::vector<Solicitud>& a, int k) {
    if (a.empty()) return -1;
    return bs_rec(a, 0, (int)a.size(), k);
}
