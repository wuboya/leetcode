//
//  main.cpp
//  279perfect
//
//  Created by WuBoya on 16/4/13.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> ret(n + 1, INT_MAX);// ret[i]表示数字i需要的最少的平方数
        ret[0] = 0;
        ret[1] = 1;
        for (int i = 2; i <= n; ++ i) {
            for (int j = 1; j * j <= i; ++ j) {
                ret[i] = min(ret[i], ret[i - j * j] + 1);
                //printf("%d %d\n", i, ret[i]);
            }
        }
        return ret[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    printf("%d\n", s.numSquares(12));
    return 0;
}
