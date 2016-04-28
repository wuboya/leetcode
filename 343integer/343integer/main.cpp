//
//  main.cpp
//  343integer
//
//  Created by WuBoya on 16/4/28.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> maxProduct(n + 1, 0);
        maxProduct[1] = 1;
        maxProduct[2] = 1;
        maxProduct[3] = 2;
        for (int i = 4; i <= n; ++ i) {
            for (int j = 2; j <= i / 2; ++ j) {
                int a = maxProduct[j] < j ? j : maxProduct[j];
                int b = maxProduct[i - j] < i - j ? i - j : maxProduct[i - j];
                maxProduct[i] = max(maxProduct[i], a * b);
                //printf("%d %d %d %d\n", i, j, a, b);
            }
        }
        return maxProduct[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    for (int i = 1; i <= 10; ++ i) {
        printf("%d: %d\n", i, s.integerBreak(i));
    }
    return 0;
}
