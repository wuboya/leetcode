//
//  main.cpp
//  337house
//
//  Created by WuBoya on 16/4/8.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
public:
    TreeNode(int val, TreeNode *left = NULL, TreeNode *right = NULL)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
public:
    TreeNode *left, *right;
    int val;
};

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> ret = robsub(root);
        return max(ret[0], ret[1]);
    }
private:
    vector<int> robsub(TreeNode* root) {
        vector<int> ret(2, 0);// robsub每次返回两个数，0表示不抢root，1表示抢root
        if (!root) return ret;
        
        vector<int> left = robsub(root -> left);
        vector<int> right = robsub(root -> right);
        
        ret[0] = max(left[0], left[1]) + max(right[0], right[1]);// 如果不抢root，那么左右两个孩子都可以不抢，也可以抢
        ret[1] = root -> val + left[0] + right[0];// 如果抢root，那么左右两个孩子都只能不抢
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    TreeNode* leftright = new TreeNode(4);
    TreeNode* left = new TreeNode(1, NULL, leftright);
    TreeNode* right = new TreeNode(3);
    TreeNode* root = new TreeNode(2, left, right);
    cout << s.rob(root);
    return 0;
}
