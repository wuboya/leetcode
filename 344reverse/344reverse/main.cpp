//
//  main.cpp
//  344reverse
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
    string reverseString(string s) {
        int len = s.length();
        int l = 0, r = len - 1;
        while (l <= r) {
            swap(s[l], s[r]);
            l ++;
            r --;
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    printf("%s\n", s.reverseString("hello").c_str());
    printf("%s\n", s.reverseString("leetcode").c_str());
    printf("%s\n", s.reverseString("Aa").c_str());
    
    return 0;
}
