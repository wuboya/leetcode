//
//  main.cpp
//  309best
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        
        vector<int> f(n, 0);
        bool cooldown = false;
        
        int maxTemp = -1 * prices[0];
        for (int i = 1; i < n; ++ i) {
            if (cooldown) {
                f[i] = f[i - 1];
                cooldown = false;
            } else {
                f[i] = prices[i] + maxTemp;
                maxTemp = max(maxTemp, f[i - 1] - prices[i]);
                cooldown = true;
            }
        }
        
        return f[n - 1];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(0);
    v.push_back(2);
    /*v.push_back(1);
    v.push_back(5);
    v.push_back(8);
    v.push_back(4);
    v.push_back(3);
    v.push_back(6);
    v.push_back(4);
    v.push_back(4);*/
    printf("%d\n", s.maxProfit(v));
    return 0;
}
