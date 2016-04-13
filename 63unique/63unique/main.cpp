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
        vector<vector<int>> f(rowNum, vector<int>(colNum, 0));// f(i,j)表示到达(i,j)的路径数量
        
        for (int j = 0; j < colNum; ++ j) {
            if (obstacleGrid[0][j] == 0) {
                f[0][j] = 1;
            } else {
                for (int k = j; k < colNum; ++ k)
                    f[0][k] = 0;
                break;
            }
        }
        
        for (int i = 0; i < rowNum; ++ i) {
            if (obstacleGrid[i][0] == 0) {
                f[i][0] = 1;
            } else {
                for (int k = i; k < rowNum; ++ k)
                    f[k][0] = 0;
                break;
            }
        }
        
        for (int i = 1; i < rowNum; ++ i) {
            for (int j = 1; j < colNum; ++ j) {
                if (obstacleGrid[i][j] == 0)
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                else
                    f[i][j] = 0;
            }
        }
        
        return f[rowNum - 1][colNum - 1];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> v(3, vector<int>(3, 0));
    v[1][1] = 1;
    cout << s.uniquePathsWithObstacles(v);
    return 0;
}
