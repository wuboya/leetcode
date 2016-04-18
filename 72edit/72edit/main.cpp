//
//  main.cpp
//  72edit
//
//  Created by WuBoya on 16/4/18.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        // f(i, j)表示将word1[0, i - 1]转化为word2[0,j - 1]所需要的最少操作数，1 <= i <= m, 1 <= j <= n, 0表示空串
        // 替换：f[i][j] = f[i - 1][j - 1] + 1
        // 删除（word1[i - 1]）：f[i][j] = f[i - 1][j] + 1
        // 插入（word2[j - 1]）：f[i][j] = f[i][j - 1] + 1
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        
        for (int i = 0; i <= m; ++ i)
            f[i][0] = i;
        for (int i = 0; i <= n; ++ i)
            f[0][i] = i;
        
        for (int i = 1; i <= m; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                if (word1[i - 1] == word2[j - 1])
                    f[i][j] = f[i - 1][j - 1];
                else
                    f[i][j] = min(f[i - 1][j - 1] + 1, min(f[i - 1][j] + 1, f[i][j - 1] + 1));
            }
        }
        
        return f[m][n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    printf("%d", s.minDistance("rabbit", "bit"));
    return 0;
}
