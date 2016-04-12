//
//  main.cpp
//  108convert
//
//  Created by WuBoya on 16/4/12.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    TreeNode (int val, TreeNode* left = NULL, TreeNode* right = NULL) {
        this -> val = val;
        this -> left = left;
        this -> right = right;
    }
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        if (nums.empty())
            return root;
        
        root = helper(nums, 0, nums.size() - 1);
        return root;
    }
private:
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if (start > end)
            return NULL;
        if (start == end) {
            TreeNode* node = new TreeNode(nums[start]);
            return node;
        }
        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node -> left = helper(nums, start, mid - 1);
        node -> right = helper(nums, mid + 1, end);
        return node;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums;
    /*for (int i = 1; i <= 5; ++ i)
        nums.push_back(i);*/
    nums.push_back(0);
    TreeNode* BST = s.sortedArrayToBST(nums);
    return 0;
}
