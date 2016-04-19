//
//  main.cpp
//  162find
//
//  Created by WuBoya on 16/4/19.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (nums[mid - 1] < nums[mid]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v = {2, 1};
    printf("%d", s.findPeakElement(v));
    return 0;
}
