//
//  main.cpp
//  318maximum
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
    int maxProduct(vector<string>& words) {
        int len = words.size();
        vector<int> mask(len, 0);
        for (int i = 0; i < len; ++ i) {
            string word = words[i];
            for (int j = 0; j < word.length(); ++ j) {
                mask[i] |= 1 << (word[j] - 'a');
            }
        }
        
        int maxp = 0;
        for (int i = 0; i < len; ++ i) {
            for (int j = 0; j < i; ++ j) {
                if ((mask[i] & mask[j]) == 0) {
                    maxp = max(maxp, int(words[i].length() * words[j].length()));
                }
            }
        }
        return maxp;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> v = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    printf("%d", s.maxProduct(v));
    return 0;
}
