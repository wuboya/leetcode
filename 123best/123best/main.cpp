//
//  main.cpp
//  123best
//
//  Created by WuBoya on 16/4/13.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2)
            return 0;
        
        vector<int> f(len, 0);// f[i] = num[i] - min(num[j]), 0 <= j < i, 表示在i时刻卖出得到的最大收益
        vector<int> g(len, 0);// g[i] = max(num[j]) - num[i], i < j <= len - 1, 表示在i时刻买入得到的最大收益
        vector<int> maxf(len, 0);// maxf[i] = max(f[j]), 0 <= j < i, 表示i时刻前卖出得到的最大收益
        vector<int> maxg(len, 0);// maxg[i] = max(g[j]), i < j <= len - 1, 表示i时刻后买入得到的最大收益
        
        int minPre = prices[0];
        for (int i = 1; i < len; ++ i) {
            f[i] = prices[i] - minPre;
            maxf[i] = max(maxf[i - 1], f[i]);
            minPre = min(prices[i], minPre);
        }
        
        int maxSuf = prices[len - 1];
        for (int i = len - 2; i >= 0; -- i) {
            g[i] = maxSuf - prices[i];
            maxg[i] = max(maxg[i + 1], g[i]);
            maxSuf = max(prices[i], maxSuf);
        }
        
        int maxProfit = maxf[1] + maxg[2];
        for (int i = 2; i < len - 2; ++ i) {// 做两笔交易的最大利润
            maxProfit = max(maxProfit, maxf[i] + maxg[i + 1]);
        }
        for (int i = 1; i < len; ++ i) {// 做一笔交易的最大利润
            maxProfit = max(maxProfit, maxf[i]);
        }
        return maxProfit;
        
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v;
    /*v.push_back(2);
    v.push_back(9);
    v.push_back(2);
    v.push_back(3);
    v.push_back(8);
    v.push_back(1);
    v.push_back(5);
    v.push_back(8);
    v.push_back(4);
    v.push_back(3);
    v.push_back(6);
    v.push_back(4);
    v.push_back(4);*/
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    cout << s.maxProfit(v);
    return 0;
}
