//
//  main.cpp
//  327count
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
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // 这一题不能用滑动窗口做，因为数组元素不全是正数，增加或减少一个元素并不能保证sum也一定增加或减少，因此不能根据sum来调整left和right
        if (nums.empty() || lower > upper)
            return 0;
        
        int len = nums.size();
        vector<long> sums(len + 1, 0);// sums[i]表示0...i-1的前缀和，i >= 1, sums[j] - sums[i]表示[i,j)的和
        for (int i = 0; i < len; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return countMergeSort(sums, 0, len + 1, lower, upper);
    }
    
    int countMergeSort(vector<long> &sums, int left, int right, int lower, int upper) {
        if (right - left <= 1) {// [left, right)
            return 0;
        }
        int mid = (left + right) / 2;
        int count = countMergeSort(sums, left, mid, lower, upper) + countMergeSort(sums, mid, right, lower, upper);
        
        int j = mid, k = mid, t = mid, len = 0;
        vector<long> cache(right - left, 0);
        for (int i = left, r = 0; i < mid; ++i, ++r) {// k, j在右半部分，i在左半部分
            while (k < right && sums[k] - sums[i] < lower) k++;// 对每一个i，找到第一个k，使得sums[k] - sums[i] >= lower
            while (j < right && sums[j] - sums[i] <= upper) j ++;// 对每一个i，找到第一个j，使得sums[j] - sums[i] > upper
            count += j - k;
            while (t < right && sums[t] < sums[i]) {
                cache[r] = sums[t];
                r++;
                t++;
            }
            cache[r] = sums[i];
            len = r;
        }
        
        for (int i = 0; i <= len; ++i) {
            sums[left + i] = cache[i];
        }
        
        return count;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v = {-2, 5, -1};
    printf("%d\n", s.countRangeSum(v, -2, 2));
    return 0;
}
