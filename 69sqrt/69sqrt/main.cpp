//
//  main.cpp
//  69sqrt
//
//  Created by WuBoya on 16/4/12.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        // 1: l初始化为-x而不是1
        // 2: l和r应该为long long，因为l + r + 1可能超出int范围
        long long l = -1 * x, r = x;
        while (l < r) {
            long long mid = (l + r + 1) / 2;
            if (mid * mid > x) {
                r = mid - 1;
            } else {
                l = mid;
            }
            //printf("%lld %lld %lld\n", l, r, mid);
        }
        return (int)l;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    printf("%d", s.mySqrt(2147395599));
    return 0;
}
