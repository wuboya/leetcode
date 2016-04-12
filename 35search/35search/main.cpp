//
//  main.cpp
//  35search
//
//  Created by WuBoya on 16/4/12.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if (nums.empty() || target <= nums[0])
            return 0;
        if (target > nums[len - 1])
            return len;
        
        int l = 0, r = len - 1;

        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid;
        }
        return l + 1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(6);
    Solution s;
    cout << s.searchInsert(v, 5) << endl;
    cout << s.searchInsert(v, 2) << endl;
    cout << s.searchInsert(v, 7) << endl;
    cout << s.searchInsert(v, 0) << endl;
    return 0;
}
