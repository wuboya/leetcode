//
//  main.cpp
//  139word
//
//  Created by WuBoya on 16/4/15.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length();
        vector<bool> f(n + 1, false);// f[i]表示截止到当前位置的字符串是否可以在字典中找到
        f[0] = true;
        for (int i = 1; i <= n; ++ i) {
            for (int j = i - 1; j >= 0; -- j) {
                if (f[j]) {
                    string word = s.substr(j, i - j);
                    if (wordDict.find(word) != wordDict.end()) {
                        f[i] = true;
                        break;
                    }
                }
            }
        }
        return f[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    unordered_set<string> wordDict = {"leet", "code"};
    printf("%d", s.wordBreak("leetcode", wordDict));
    return 0;
}
