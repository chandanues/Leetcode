// 1415. The k-th Lexicographical String of All Happy Strings of Length n

/*
A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

 

Example 1:

Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
Example 2:

Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.
Example 3:

Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"

*/

#include<bits/stdc++.h>
using namespace std;

// using DFS
void dfs(int n,string temp,vector<string>&nums) {
    if(temp.size()==n) {
        nums.push_back(temp);
        return ;
    }

    for(auto it: {'a','b','c'}){
        if(temp.empty()||temp.back()!=it){
            dfs(n,temp+it,nums);
        }
    }
}

// using BFS
string bfs(int n,int k){
    vector<string>res;
    queue<string>q;
    q.push("a");
    q.push("b");
    q.push("c");

    while(!q.empty()){
        auto front=q.front();
        q.pop();
        if(front.size()==n){
            res.push_back(front);
            if(res.size()==k) return front;
            continue;
        }
        
        for(auto it: {'a','b','c'}){
            if(front.back()!=it){
                q.push(front+it);
            }
        }
    }
    return "";
}

string getHappyString(int n,int k){
    // vector<string>res;
    // dfs(n,"",res);
    // return res.size()<k?"":res[k-1];
    return bfs(n,k);
}

int main() {
    cout<<getHappyString(3,9)<<endl;
    return 0;
}
