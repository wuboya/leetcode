//
//  main.cpp
//  63unique
//
//  Created by WuBoya on 16/4/12.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        
        int rowNum = obstacleGrid.size(), colNum = obstacleGrid[0].size();
        vector<vector<int>> f(rowNum + 1, vector<int>(colNum + 1, 0));// f(i + 1, j + 1)表示到达(i, j)的路径数量
        f[0][1] = 1;// 将f扩大一行一列，并将新的f的第一行第二个元素置为1，这样不用特殊初始化计算边界（第一行和第一列）的f，6ms to 4ms
        
        for (int i = 1; i <= rowNum; ++ i) {
            for (int j = 1; j <= colNum; ++ j) {
                if (obstacleGrid[i - 1][j - 1] == 0)// 注意f(i + 1, j + 1)记录的是(i, j)的情况
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        
        return f[rowNum][colNum];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> v(3, vector<int>(3, 0));
    v[1][1] = 1;
    cout << s.uniquePathsWithObstacles(v);
    return 0;
}
