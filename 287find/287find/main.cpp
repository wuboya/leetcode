//
//  main.cpp
//  287find
//
//  Created by WuBoya on 16/4/12.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            int count = 0;
            for (int i = 0; i < n + 1; ++ i) {
                if (nums[i] <= mid) {
                    count ++;
                }
            }
            if (count > mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    cout << s.findDuplicate(v);
    return 0;
}
