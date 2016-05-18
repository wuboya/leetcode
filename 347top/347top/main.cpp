//
//  main.cpp
//  347top
//
//  Created by WuBoya on 16/5/18.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*unordered_map<int, int> umap;
        for (int num : nums) {
            ++umap[num];
        }
        
        vector<int> ret;
        priority_queue<pair<int, int>> pq;
        for (auto it = umap.begin(); it != umap.end(); ++it) {
            pq.push(make_pair(it -> second, it -> first));// (frequency, number)
            if (pq.size() > (int)umap.size() - k) {// 总共的个数是umap.size()个，选k个，剩余umap.size() - k个，当pq中元素个数大于剩余个数时就可以开始push_back
                ret.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ret;*/
        
        unordered_map<int, int> m;
        for (int num : nums)
            ++m[num];
        
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto p : m)
            buckets[p.second].push_back(p.first);
        
        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v = {1,1,1,2,2,3};
    vector<int> ret = s.topKFrequent(v, 2);
    for (int i = 0; i < ret.size(); ++ i) {
        cout << ret[i] << ' ';
    }
    return 0;
}
