//
//  main.cpp
//  140word
//
//  Created by WuBoya on 16/4/18.
//  Copyright (c) 2016年 WuBoya. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    unordered_map<string, vector<string>> memory;
    
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        // acceleration 1: 检查之前是否已经是计算过，如果计算过直接返回
        if (memory.find(s) != memory.end())
            return memory[s];
        
        // acceleration 2: 检查是否存在解，如果不存在解直接返回
        vector<string> ret;
        int n = s.size();
        bool notfound = true;
        for (int i = n - 1; i >=0; -- i) {
            if (wordDict.find(s.substr(i)) != wordDict.end()) {
                notfound = false;
                break;
            }
        }
        if (notfound) return ret;
        
        // 计算
        if (wordDict.find(s) != wordDict.end())
            ret.push_back(s);
        
        // 16ms
       /* for (int i = 1; i < n; ++ i) {// i表示最后一个单词的起始位置
            string word = s.substr(i);
            if (wordDict.find(word) != wordDict.end()) {
                // 前缀
                string prefix = s.substr(0, i);
                vector<string> prefixRet = wordBreak(prefix, wordDict);
                // 拼接
                for (int j = 0; j < prefixRet.size(); ++ j)
                    prefixRet[j] += " " + word;
                // 记录
                ret.insert(ret.end(), prefixRet.begin(), prefixRet.end());
            }
        }*/
        
        // 16ms
        /*for (int i = 1; i < n; ++ i) {// i表示最后一个单词的起始位置
            string word = s.substr(i);
            if (wordDict.find(word) != wordDict.end()) {
                string prefix = s.substr(0, i);
                vector<string> prefixRet = wordBreak(prefix, wordDict);
                for (auto prefix : prefixRet) {
                    ret.push_back(prefix + " " + word);
                }
            }
        }*/
        
        // 12ms
        for (int i = n - 1; i >= 0; -- i) {// i表示第一个单词的终止位置的下一个
            if (wordDict.find(s.substr(0, i)) != wordDict.end()) {
                vector<string> suffixRet = wordBreak(s.substr(i), wordDict);
                for (auto suffix : suffixRet) {
                    ret.push_back(s.substr(0, i) + " " + suffix);
                }
            }
        }
        
        // 存储
        memory[s] = ret;
        return ret;
        
        
        // TLE version: 对aaaa...aaa, [a, aa, aaa, ...]超时
        /*int n = s.size();
        vector<vector<string>> part;// part[j]表示到位置j的各种组合
        vector<string> v(1, "");
        part.push_back(v);
        
        for (int i = 1; i <= n; ++ i) {
            vector<string> v;
            part.push_back(v);
            for (int j = i - 1; j >= 0; -- j) {
                if (part[j].size() > 0) {
                    string word = s.substr(j, i - j);
                    if (wordDict.find(word) != wordDict.end()) {
                        for (int k = 0; k < part[j].size(); ++ k) {
                            part[i].push_back(part[j][k] == "" ? word : (part[j][k] + " " + word));
                        }
                    }
                }
            }
        }
        return part[n];*/
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    unordered_set<string> wordDict = {"c", "at", "ats", "cat", "cats", "and", "sand", "dog"};
    vector<string> ret = s.wordBreak("catsanddog", wordDict);
    for (int i = 0; i < ret.size(); ++ i) {
        printf("%s\n", ret[i].c_str());
    }
    return 0;
}
