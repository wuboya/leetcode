//
//  main.cpp
//  29divide
//
//  Created by WuBoya on 16/4/12.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long long dvd = labs(dividend);// 注意必须是long long，因为abs(INT_MIN) = INT_MAX + 1，超出int范围
        long long dvs = labs(divisor);
        
        long long l = 0, r = dvd;
        while (l < r) {
            long long mid = (l + r + 1) / 2;
            if (dvs * mid > dvd) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        
        return sign * (int)l;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.divide(-5, -2) << endl;
    cout << s.divide(-5, 2) << endl;
    cout << s.divide(2, -5) << endl;
    cout << s.divide(2, 5) << endl;
    cout << s.divide(0, -2) << endl;
    cout << s.divide(2147483647, 1) << endl;
    cout << s.divide(-2147483648, -1) << endl;// 特殊情况：计算结果为INT_MAX + 1，超出INT范围，答案为INT_MAX

    return 0;
}
