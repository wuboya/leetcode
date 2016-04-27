//
//  main.cpp
//  Baidu2
//
//  Created by WuBoya on 16/4/21.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
using namespace std;

int trans(int x)
{
    int y = 0;
    while (x > 0) {
        int z = x % 10;
        if (z == 4)
            y = y * 2;
        if (z == 7)
            y = y * 2 + 1;
        x /= 10;
    }
    return y;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int tb = trans(b);
    for (int i = a + 1; i < 200000; ++i)
        if (trans(i) == tb) {
            cout << i << endl;
            break;
        }
    
    return 0;
}
