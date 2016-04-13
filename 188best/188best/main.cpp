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
        
        // k + 1行n列，f(k, i)表示k次交易在前i个数完成的最大利润
        // f(k, i) = f(k, i - 1), 最后一次卖不在i or
        //          max(f(k - 1, j - 1) + prices[i] - prices[j]), 2(k - 1) <= j <= i - 1, 最后一次卖在i，买在j
        vector<vector<int>> f(k + 1, vector<int>(n, 0));
        
        for (int s = 1; s <= k; ++ s) {
            /*int maxPre = INT_MIN;
             for (int i = 2 * s - 1; i < n; ++ i) {// 第i次交易最少在2 * s - 1个数的时候完成
             int temp = f[s - 1][i - 2] - prices[i - 1];// i = 1的情况只有在s = 1的时候出现
             f[s][i] = max(f[s][i - 1], prices[i] + max(maxPre, temp));
             maxPre = max(maxPre, temp);
             }*/
            int maxTemp = -1 * prices[0];
            for (int i = 1; i < n; ++ i) {
                f[s][i] = max(f[s][i - 1], prices[i] + maxTemp);
                maxTemp = max(maxTemp, f[s - 1][i - 1] - prices[i]);
            }
        }
        
        /*int maxProfit = 0;
         for (int s = 0; s <= k; ++ s) {
         maxProfit = max(maxProfit, f[s][n - 1]);
         }
         
         return maxProfit;*/
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
    
    cout << s.maxProfit(1000000000, v);
    return 0;
}
