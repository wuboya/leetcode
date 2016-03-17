//
//  main.cpp
//  3longest
//
//  Created by WuBoya on 16/3/5.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        int maxendinghere = 1, maxsofar = 1;
        int starth = 0;// 保留i-1时maxendinghere子串的起始位置，结束位置一定是i-1
        
        for (int i = 1; i < s.length(); i ++) {
            bool find = false;
            for (int j = starth; j < i; j ++) {// 检查i字符在i-1的maxendinghere子串中是否出现，如果出现，为了取i字符要去掉重复前的部分
                if (s[i] == s[j]) {
                    maxendinghere = i - j;
                    starth = j + 1;
                    find = true;
                    break;
                }
            }
            if (!find) {
                maxendinghere ++;
            }
            if (maxendinghere > maxsofar) {// 到i位置最长的子串，要么包含i字符，要么不包含i字符
                maxsofar = maxendinghere;
            }
        }
        return maxsofar;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int ans = s.lengthOfLongestSubstring("aab");
    cout << ans;
    return 0;
}
