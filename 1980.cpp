/*

Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.

*/

#include <bits/stdc++.h>
using namespace std;

// brute force solution
string f_(int idx, string temp, vector<string>&nums){
    if(temp.size()==nums.size()) {
        if(find(nums.begin(),nums.end(),temp)==nums.end()){
            return temp;
        }
        return "";
    }

    if(idx>=nums.size()) return "";

    string ans1=f_(idx+1,temp+'0',nums);
    string ans2=f_(idx+1,temp+'1',nums);

    if(ans1!="") return ans1;
    else if(ans2!="") return ans2;
    return "";
}

string f_(vector<string>&nums){
    int n=nums.size();
    return f(n, "", nums);
}

// optimal solution
int f(vector<string>&nums){
    string res="";
    int n=nums.size();
    for(int i=0;i<n;i++){
        res+=(nums[i][i]=='1')?'0':'1';
    }
    return res;
}

int main() {
    return 0;
}