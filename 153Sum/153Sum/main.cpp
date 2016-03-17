//
//  main.cpp
//  153Sum
//
//  Created by WuBoya on 16/3/5.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        
        sort(nums.begin(), nums.end());
        
        int len = (int)nums.size();
        for (int i = 0; i < len; i ++) {
            int temp = -1 * nums[i];
            int left = i + 1;
            int right = len - 1;
            
            while (left < right) {// 注意循环条件
                int sum = nums[left] + nums[right];
                if (sum == temp) {
                    vector<int> oneret;
                    oneret.push_back(nums[i]);
                    oneret.push_back(nums[left]);
                    oneret.push_back(nums[right]);
                    
                    while (left < right && nums[left] == oneret[1]) left ++;// 当方案已经记录，跳过选择重复的数字
                    while (left < right && nums[right] == oneret[2]) right --;// 当方案已经记录，跳过选择重复的数字
                    
                    ret.push_back(oneret);
                } else if (sum < temp) {
                    left ++;
                } else {
                    right --;
                }
            }
            
            while (i + 1 < len && nums[i + 1] == nums[i]) i ++;// 当方案已经记录，跳过计算重复的数字
            
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v;
    v.push_back(-1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(-1);
    v.push_back(-4);
    vector<vector<int>> ans = s.threeSum(v);
    cout << ans.size();
    return 0;
}
