//
//  main.cpp
//  105construct
//
//  Created by WuBoya on 16/4/27.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0, 0, inorder.size() - 1, preorder, inorder);
    }
private:
    TreeNode* helper(int preStart, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        if (preStart > preorder.size() - 1 || inStart > inEnd)
            return root;
        
        root = new TreeNode(preorder[preStart]);
        int inIndex = 0;
        for (int i = inStart; i <= inEnd; ++ i) {
            if (inorder[i] == root -> val) {
                inIndex = i;
            }
        }
        
        root -> left = helper(preStart + 1, inStart, inIndex - 1, preorder, inorder);
        root -> right = helper(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> preorder = {-1};
    vector<int> inorder = {-1};
    TreeNode* nroot = s.buildTree(preorder, inorder);
    printf("%d", nroot -> val);
    return 0;
}
