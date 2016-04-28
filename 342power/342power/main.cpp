//
//  main.cpp
//  342power
//
//  Created by WuBoya on 16/4/28.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0x55555555) == num);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    printf("%d\n", s.isPowerOfFour(16));
    printf("%d\n", s.isPowerOfFour(15));
    return 0;
}
