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
            //printf("%d %d %d\n", l, mid, r);
            if (mid == r) {
                return nums[l] > nums[r] ? l : r;
            } else if (mid + 1 <= r && nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            } else if (mid + 1 <= r && nums[mid] > nums[mid + 1]) {
                r = mid;
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
