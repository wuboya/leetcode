//
//  main.cpp
//  345reverse
//
//  Created by WuBoya on 16/4/28.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int len = s.length();
        set<char> vowels = {'a','e','i','o','u'};
        int l = 0, r = len - 1;
        while (l <= r) {
            while (vowels.find(tolower(s[l])) == vowels.end()) {
                l ++;
            }
            while (vowels.find(tolower(s[r])) == vowels.end()) {
                r --;
            }
            //printf("%c %c\n", s[l], s[r]);
            if (l <= r) {
                swap(s[l], s[r]);
                l ++;
                r --;
            }
            //printf("%s\n", s.c_str());
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    printf("%s\n", s.reverseVowels("hello").c_str());
    printf("%s\n", s.reverseVowels("leetcode").c_str());
    printf("%s\n", s.reverseVowels("Aa").c_str());

    return 0;
}
