//
//  main.cpp
//  76minimum
//
//  Created by WuBoya on 16/4/28.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        /*vector<int> dict(128, 0);// ascii码表长度，dict[c] = t中字符c出现个数 - s中字符c出现个数
        for (char c: t) {// 统计t中字符出现个数
            dict[c] ++;
        }
        
        int count = t.size(), begin = 0, end = 0, d = INT_MAX, head = begin;
        while (end < s.size()) {// 当前s中处理的字母的下标为end
            if (dict[s[end]] > 0) {// 如果s[end]是t中出现的字母
                count --;// t中还需要匹配的字母个数减1
            }
            dict[s[end]] --;// 不管是不是t中出现的字母都要修改dict
            end ++;// 考虑下一个字母
            
            while (count == 0) {// 如果t中还需要匹配的字母个数为0，即t中字母已经全部出现
                if (end - begin < d) {// 如果当前窗口长度更小
                    d = end - begin;// 更新窗口长度d
                    head = begin;// 修改窗口起始位置head
                }
                if (dict[s[begin]] == 0) {// dict < 0表示s[begin]这个字符在s中出现的次数比在t中出现的次数多，dict = 0表示该字符在s中出现的次数等于在t中出现的次数，dict > 0是不可能的，因为t中字符需要全部匹配才能进入这个循环
                    count ++;// 下次要把begin放出去，增加t中还需要匹配的字母个数
                }
                dict[s[begin]] ++;// 修改dict
                begin ++;// 考虑下一个字母
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);*/
        
        // baby's version
        vector<int> countT(128, 0);
        vector<int> countS(128, 0);
        int vocT = 0, vocS = 0;// vocS表示s在[left, right)中出现的、t中出现的、count[s] >= count[t]的字符个数
        int windowLen = INT_MAX, head = 0;
        
        for(char c: t) {
            if (countT[c] == 0) vocT++;
            countT[c]++;
        }
        int left = 0, right = 0;// 左闭右开
        while (right < s.size()) {
            while (vocS != vocT && right < s.size()) {// right < s.size()：t的字符在s中找不全，right会一直往右
                char x = s[right];
                countS[x]++;
                if (countS[x] == countT[x]) {
                    vocS++;
                }
                ++right;
            }
            while (vocS == vocT && left < right) {// left < right：如果t是空字符串，satisfy会一直为true
                if (right - left < windowLen) {
                    windowLen = right - left;
                    head = left;
                }
                char x = s[left];
                if (countS[x] == countT[x]) {
                    vocS--;
                }
                countS[x]--;
                ++left;
            }
        }
        return windowLen == INT_MAX ? "" : s.substr(head, windowLen);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    printf("%s\n", s.minWindow("aaba", "aa").c_str());
    return 0;
}
