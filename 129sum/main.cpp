#include <iostream>
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
	int sumNumbers(TreeNode* root) {
		if (!root) return 0;
		return DFS(root, 0, 0);
	}
private:
	/*int DFS(TreeNode* root, int num, int sum) {
		num = num * 10 + root->val;
		if (!root->left && !root->right) {
			return num;
		}
		if (root->left) sum += DFS(root->left, num, sum);// 调用的函数return了sum，又加在了原来的sum上
		if (root->right) sum += DFS(root->right, num, sum);
		return sum;
	}*/
    int DFS(TreeNode* root, int num) {
        num = num * 10 + root -> val;
        if (!root -> left && !root -> right) {
            return num;
        }
        int sum = 0;
        if (root -> left) sum += DFS(root -> left, num);
        if (root -> right) sum += DFS(root -> right, num);
        return sum;
    }
};

int main()
{
	Solution s;
	TreeNode *rightleft = new TreeNode(0);
	TreeNode *rightright = new TreeNode(0);
	TreeNode *left = new TreeNode(1);
	TreeNode *right = new TreeNode(0, rightleft, rightright);
	TreeNode *root = new TreeNode(0, left, right);
	cout << s.sumNumbers(root) << endl;

	return 0;
}
