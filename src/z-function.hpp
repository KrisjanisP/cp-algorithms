#pragma once
#include <bits/stdc++.h>

class ZFunction {
public:
  static std::vector<int> zFunction(std::string s) {
    int n = s.size();
    std::vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
      if (i < r)
        z[i] = std::min(r - i, z[i - l]);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
        z[i]++;
      }
      if (i + z[i] > r) {
        l = i;
        r = i + z[i];
      }
    }
    return z;
  }
};
