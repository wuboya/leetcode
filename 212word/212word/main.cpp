//
//  main.cpp
//  212word
//
//  Created by WuBoya on 16/4/19.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode* next[26];
    string word;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        if (board.empty() || board[0].empty() || words.empty())
            return ret;
        
        TrieNode* root = buildTrieTree(words);// 根据需要查找的词构建一棵TrieTree
        
        for (int i = 0; i < board.size(); ++ i) {
            for (int j = 0; j < board[0].size(); ++ j) {
                DFS(board, i, j, root, ret);// 从二维字符数组的每一个位置开始查找TrieTree
            }
        }
        
        return ret;
    }
private:
    TrieNode* buildTrieTree(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); ++ iter) {
            string word = *iter;
            TrieNode* p = root;
            for (int i = 0; i < word.length(); ++ i) {
                int index = word[i] - 'a';
                if (!p -> next[index]) {
                    p -> next[index] = new TrieNode();
                    p -> word = "";
                }
                p = p -> next[index];
            }
            p -> word = word;
            printf("%s\n", p -> word.c_str());
        }
        
        return root;
    }
    void DFS(vector<vector<char>>& board, int x, int y, TrieNode* p, vector<string>& ret) {
        if (board[x][y] == '*' || !p -> next[board[x][y] - 'a'])
            return;
        
        p = p -> next[board[x][y] - 'a'];
        printf("%c %s\n", board[x][y], p -> word.c_str());
        if (p -> word != "") {
            ret.push_back(p -> word);
            p -> word = "";
        }
        
        char temp = board[x][y];
        board[x][y] = '*';
        if (y + 1 < board[0].size()) DFS(board, x, y + 1, p, ret);
        if (x + 1 < board.size()) DFS(board, x + 1, y, p, ret);
        if (x - 1 >= 0) DFS(board, x - 1, y, p, ret);
        if (y - 1 >= 0) DFS(board, x, y - 1, p, ret);
        board[x][y] = temp;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    //vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    //vector<string> words = {"oath","pea","eat","rain"};
    vector<vector<char>> board = {{'a','b'},{'c','d'}};
    vector<string> words = {"ab","cb","ad","bd","ac","ca","da","bc","db","adcb","dabc","abb","acb"};
    
    vector<string> ret = s.findWords(board, words);
    for (vector<string>::iterator iter = ret.begin(); iter != ret.end(); ++ iter) {
        printf("%s\n", (*iter).c_str());
    }
    return 0;
}
