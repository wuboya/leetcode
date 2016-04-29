//
//  main.cpp
//  209minimum
//
//  Created by WuBoya on 16/4/29.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = 0;
        int minLen = INT_MAX, sum = 0;
        
        while (right < len) {
            if (sum < s && right < len) {
                sum += nums[right];
                right ++;
            }
            while (sum >= s && left < right) {
                minLen = min(minLen, right - left);
                sum -= nums[left];
                left ++;
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v = {2,3,1,2,4,3};
    printf("%d\n", s.minSubArrayLen(7, v));
    return 0;
}
