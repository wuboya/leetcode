//
//  main.cpp
//  215kth
//
//  Created by WuBoya on 16/3/27.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int p = 0, r = nums.size() - 1;
        
        while (p < r) {
            int len = r - p + 1;
            swap(nums[p + rand() % len], nums[r]);
            //int pos = partition(nums, p, r);
			int pos = partition2(nums, p, r);			
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

	int partition2(vector<int>& nums, int p, int r) {
		int x = nums[r];
		auto it = std::partition(nums.begin() + p, nums.begin() + r, [x](int t) { return t >= x; });
		swap(nums[r], *it);
		return it - nums.begin();
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
    cout << s.findKthLargest(v, 2) << endl;

	v.clear();
	for (int i = 1; i <= 10; ++i)
		v.push_back(i);
	random_shuffle(v.begin(), v.end());
	cout << s.findKthLargest(v, 5) << endl;

    return 0;
}
