//
//  main.cpp
//  97interleaving
//
//  Created by WuBoya on 16/4/18.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 == 0)
            return s3 == s2;
        if (len2 == 0)
            return s3 == s1;
        if (len1 + len2 != len3)
            return false;
        
        //vector<vector<bool>> table(len1 + 1, vector<bool>(len2 + 1, true));
        bool table[len1 + 1][len2 + 1];
        for (int i = 0; i <= len1; ++ i) {
            for (int j = 0; j <= len2; ++ j) {
                if (i == 0 && j == 0)
                    table[i][j] = true;
                else if (i == 0)
                    table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                else if (j == 0)
                    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                else
                    table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
            }
        }
        
        return table[len1][len2];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    printf("%d\n", s.isInterleave("aabc", "abad", "aabadabc"));
    printf("%d\n", s.isInterleave("a", "b", "a"));
    printf("%d\n", s.isInterleave("a", "", "a"));
    
    return 0;
}
