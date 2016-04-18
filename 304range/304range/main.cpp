//
//  main.cpp
//  304range
//
//  Created by WuBoya on 16/4/18.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        rows = matrix.size();
        cols = matrix[0].size();
        // sums表示从matrix[0][0]到matrix[i - 1][j - 1]的和
        sums = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));
        for (int i  = 1; i <= rows; ++ i) {
            for (int j = 1; j <= cols; ++ j) {
                sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row2 + 1][col1] - sums[row1][col2 + 1] + sums[row1][col1];
    }
private:
    int rows, cols;
    vector<vector<int>> sums;
};


int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    NumMatrix n(matrix);
    printf("%d\n", n.sumRegion(2, 1, 4, 3));
    printf("%d\n", n.sumRegion(1, 1, 2, 2));
    printf("%d\n", n.sumRegion(1, 2, 2, 4));
    return 0;
}
