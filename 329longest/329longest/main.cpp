//
//  main.cpp
//  329longest
//
//  Created by WuBoya on 16/4/19.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        int m = matrix.size(), n = matrix[0].size(), LIP = 1;
        vector<vector<int>> f(m, vector<int>(n, -1));// f(i, j)表示包含matrix[i][j]的LIP长度
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int length = DFS(matrix, f, m, n, i, j, INT_MIN);
                LIP = max(LIP, length);
            }
        }
    
        return LIP;
    }
private:
    int DFS(vector<vector<int>>& matrix, vector<vector<int>>& f, int m, int n, int x, int y, int pre) {
        // 将原本的先检查边界再DFS修改为先DFS再检查边界
        if (x < 0 || y < 0 || x >= m || y >= n || matrix[x][y] <= pre)
            return 0;
        // 如果之前已经计算过，那么直接返回
        if (f[x][y] != -1)
            return f[x][y];
        
        f[x][y] = max(DFS(matrix, f, m, n, x, y + 1, matrix[x][y]), max(DFS(matrix, f, m, n, x + 1, y, matrix[x][y]), max(DFS(matrix, f, m, n, x, y - 1, matrix[x][y]),DFS(matrix, f, m, n, x - 1, y, matrix[x][y])))) + 1;
        return f[x][y];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> v1 = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    vector<vector<int>> v2 = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
    vector<vector<int>> v3 = {{1, 2}};
    vector<vector<int>> v4 = {{1}};
    printf("%d\n", s.longestIncreasingPath(v1));
    printf("%d\n", s.longestIncreasingPath(v2));
    printf("%d\n", s.longestIncreasingPath(v3));
    printf("%d\n", s.longestIncreasingPath(v4));
    return 0;
}
