//
//  main.cpp
//  215kth
//
//  Created by WuBoya on 16/3/27.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int p = 0, r = nums.size() - 1;
        
        while (p < r) {
            int len = r - p + 1;
            swap(nums[p + rand() % len], nums[r]);
            int pos = partition(nums, p, r);
            if (pos == k - 1) return nums[pos];
            if (pos < k - 1) {
                p = pos + 1;

            } else {
                r = pos - 1;
            }
        }
        
        return nums[p];
    }
private:
    int partition(vector<int>& nums, int p, int r) {
        int x = nums[r];
        int i = p - 1;
        for (int j = p; j <= r - 1; j ++) {
            if (nums[j] >= x) {
                i ++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[r], nums[i + 1]);

        return i + 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v;
    v.push_back(-1);
    v.push_back(2);
    v.push_back(0);
    //v.push_back(4);
    //v.push_back(5);
    //v.push_back(6);
    cout << s.findKthLargest(v, 2);
    return 0;
}
