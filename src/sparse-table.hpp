#pragma once
#include <bits/stdc++.h>

template <typename T>
class SparseTable {
    T** st; // layer, starting index
    int n, k; // indices, layers
public:
    SparseTable(T a[], int n) {
        this->n = n;
        k = 1;
        while ((1 << k) <= n) k++;
        st = new T*[k];
        for (int i = 0; i < k; i++) {
            st[i] = new T[n];
            for (int j = 0; j < n; j++) {
                if (i == 0) st[i][j] = a[j];
                else if (j + (1 << i) - 1 < n) {
                    st[i][j] = std::min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
                }
            }
        }
    }
    SparseTable(std::vector<T> v) : SparseTable(v.data(), v.size()) {}
    ~SparseTable() {
        for (int i = 0; i < k; i++) delete[] st[i];
        delete[] st;
    }
    T query(int l, int r) {
        int j = 0; while ((1 << (j+1)) <= r - l + 1) j++;
        return std::min(st[j][l], st[j][r - (1 << j) + 1]);
    }
};
