#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Matrix:vector<vector<int>>
{
    // "inherit" vector's constructor
    using vector::vector;
    
    Matrix operator *(Matrix other)
    {
        int rows = size();
        int cols = other[0].size();
        Matrix res(rows, vector<int>(cols));
        for(int i=0;i<rows;i++)
            for(int j=0;j<other.size();j++)
                for(int k=0;k<cols;k++)
                    res[i][k]+=at(i).at(j)*other[j][k];
        return res;
    }
};