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
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> f(m, vector<int>(n, -1));// f(i, j)表示包含matrix[i][j]的LIP长度
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (f[i][j] == -1) {
                    f[i][j] = 1;
                    DFS(matrix, f, m, n, i, j);
                }
            }
        }
        
        int LIP = 1;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                LIP = max (LIP, f[i][j]);
            }
        }
        
        return LIP;
    }
private:
    void DFS(vector<vector<int>>& matrix, vector<vector<int>>& f, int m, int n, int x, int y) {
        int temp = f[x][y] + 1;
        if (y + 1 < n && matrix[x][y + 1] > matrix[x][y] && f[x][y + 1] < temp) {
            f[x][y + 1] = temp;
            DFS(matrix, f, m, n, x, y + 1);
        }
        if (x + 1 < m && matrix[x + 1][y] > matrix[x][y] && f[x + 1][y] < temp) {
            f[x + 1][y] = temp;
            DFS(matrix, f, m, n, x + 1, y);
        }
        if (y - 1 >= 0 && matrix[x][y - 1] > matrix[x][y] && f[x][y - 1] < temp) {
            f[x][y - 1] = temp;
            DFS(matrix, f, m, n, x, y - 1);
        }
        if (x - 1 >= 0 && matrix[x - 1][y] > matrix[x][y] && f[x - 1][y] < temp) {
            f[x - 1][y] = temp;
            DFS(matrix, f, m, n, x - 1, y);
        }
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
