//
//  main.cpp
//  188best
//
//  Created by WuBoya on 16/4/13.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2)
            return quickSolve(prices);
        
        // k + 1行n列，f(k, i)表示【至多】k次交易在前i个数完成的最大利润
        // f(k, i) = f(k, i - 1), 最后一次卖不在i or
        //          max(f(k - 1, j - 1) + prices[i] - prices[j]), 2(k - 1) <= j <= i - 1, 最后一次卖在i，买在j
        vector<vector<int>> f(k + 1, vector<int>(n, 0));
        
        for (int s = 1; s <= k; ++ s) {
            int maxPre = INT_MIN;
            int maxTemp = -1 * prices[0];
            for (int i = 1; i < n; ++ i) {
                f[s][i] = max(f[s][i - 1], prices[i] + maxTemp);
                maxTemp = max(maxTemp, f[s - 1][i - 1] - prices[i]);
            }
        }
        
        return f[k][n - 1];
    }
private:
    int quickSolve(vector<int>& prices) {
        int n = prices.size(), maxProfit = 0;
        for (int i = 1; i < n; i ++)
            if (prices[i] > prices[i - 1])
                maxProfit += prices[i] - prices[i - 1];
        return maxProfit;
    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(6);
    v.push_back(5);
    v.push_back(0);
    v.push_back(3);
    cout << s.maxProfit(2, v);
    return 0;
}
