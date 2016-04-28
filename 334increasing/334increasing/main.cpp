//
//  main.cpp
//  334increasing
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
    bool increasingTriplet(vector<int>& nums) {// 类似最长递增子序列
        int len = nums.size();
        vector<int> f(len + 1, 1);// f(i)为包含i的最长递增子序列，f(i) = max(f(j) + 1), j < i && nums[j] < nums[i]
        for (int i = 1; i < len; ++ i) {
            for (int j = i - 1; j >= 0; -- j) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j] + 1);
                }
                if (f[i] >= 3) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {5,4,3,2,1};
    printf("%d\n", s.increasingTriplet(v1));
    printf("%d\n", s.increasingTriplet(v2));
    return 0;
}
