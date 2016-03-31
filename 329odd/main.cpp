//
//  main.cpp
//  329odd
//
//  Created by WuBoya on 16/3/31.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* n) {
        this -> val = x;
        this -> next = n;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head -> next) return head;
        
        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* even2 = head -> next;
        
        // 这个事情是不可以分开做的…因为修改完odd之后even在odd修改之后的基础上操作就会有变化
        /*while (odd -> next && odd -> next -> next) {
            odd -> next = odd -> next -> next;
            odd = odd -> next;
        }
        while (even -> next && even -> next -> next) {
            even -> next = even -> next -> next;
            even = even -> next;
        }
        odd -> next = even2;
        even -> next = NULL;*/
        
        while (even && even -> next) {
            odd -> next = odd -> next -> next;
            even -> next = even -> next -> next;
            odd = odd -> next;
            even = even -> next;
        }
        odd -> next = even2;
        return head;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    ListNode* n8 = new ListNode(8);
    ListNode* n7 = new ListNode(7, n8);
    ListNode* n6 = new ListNode(6, n7);
    ListNode* n5 = new ListNode(5, n6);
    ListNode* n4 = new ListNode(4, n5);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);

    ListNode* newHead = s.oddEvenList(n1);
    while (newHead) {
        cout << newHead -> val << ' ';
        newHead = newHead -> next;
    }
    return 0;
}
