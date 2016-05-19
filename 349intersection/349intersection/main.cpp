//
//  main.cpp
//  349intersection
//
//  Created by WuBoya on 16/5/19.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        if (nums1.empty() || nums2.empty())
            return ret;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len1 = nums1.size(), len2 = nums2.size();
        int index1 = 0, index2 = 0;
        
        while (index1 < len1 - 1 && index2 < len2 - 1) {
            while (index1 < len1 - 1 && nums1[index1] == nums1[index1 + 1]) index1++;// 注意条件index1 < len1 - 1
            while (index2 < len2 - 1 && nums2[index2] == nums2[index2 + 1]) index2++;// 注意条件index2 < len2 - 1
            if (nums1[index1] == nums2[index2]) {
                ret.push_back(nums1[index1]);
                index1++;
                index2++;
            } else if (nums1[index1] < nums2[index2]) {
                index1++;
            } else {
                index2++;
            }
        }
        
        if (index1 == len1 - 1) {
            while (index2 < len2 && nums2[index2] < nums1[index1]) index2++;
            if (nums2[index2] == nums1[index1])
                ret.push_back(nums2[index2]);
        } else if (index2 == len2 - 1) {
            while (index1 < len1 && nums1[index1] < nums2[index2]) index1++;
            if (nums1[index1] == nums2[index2])
                ret.push_back(nums1[index1]);
        }
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v1 = {1,2,2,1};
    vector<int> v2 = {2,2};
    vector<int> ret = s.intersection(v1, v2);
    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i] << ' ';
    }
    return 0;
}
