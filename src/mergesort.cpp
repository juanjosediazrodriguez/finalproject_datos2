#include "mergesort.hpp"

static void merge_sort_rec(std::vector<Solicitud>& a, int l, int r, std::vector<Solicitud>& tmp) {
    if (r - l <= 1) return;
    int m = (l + r) / 2;
    merge_sort_rec(a, l, m, tmp);
    merge_sort_rec(a, m, r, tmp);
    int i = l, j = m, k = l;
    while (i < m || j < r) {
        if (j >= r || (i < m && (a[i].tenure > a[j].tenure || (a[i].tenure == a[j].tenure)))) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }
    for (int t = l; t < r; ++t) a[t] = tmp[t];
}


void merge_sort_desc(std::vector<Solicitud>& a) {
    std::vector<Solicitud> tmp(a.size());
    merge_sort_rec(a, 0, (int)a.size(), tmp);
}
