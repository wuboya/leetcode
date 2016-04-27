//
//  main.cpp
//  Baidu1
//
//  Created by WuBoya on 16/4/21.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
using namespace std;

const int maxn = 50000 + 5;
int left[maxn];
int right[maxn];

int main(int argc, const char * argv[]) {
    string s;
    int markNum = 0;
    cin >> s;
    for (int i = 0; i < s.size(); ++ i) {
        if (s[i] == '?') {
            markNum ++;
        }
    }
    for (int i = 0; i < markNum; ++ i) {
        cin >> left[i] >> right[i];
    }
    return 0;
}
