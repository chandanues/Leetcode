/*

1780. Check if Number is a Sum of Powers of Three
Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.

 

Example 1:

Input: n = 12
Output: true
Explanation: 12 = 31 + 32
Example 2:

Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34
Example 3:

Input: n = 21
Output: false
 
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binary_exp(int a,int b){
        int ans=1;
        while(b>0){
            if(b&1) ans*=a;
            a*=a;
            b>>=1; 
        }
        return ans;
    }

    int closest_pow(int num){
        int low=0,high=14;
        int ans=low;
        while(low<=high){
            int mid=(low+high)>>1;
            if(binary_exp(3,mid)<=num){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }

    bool f(int num){
        int cl=closest_pow(num);
        cout<<cl<<endl;
        while(cl>=0){
            int be=binary_exp(3,cl);
            if(be<=num) num-=be;
            cl--;
            if(num==0) return true;
        } 
        return false;
    }
    bool checkPowersOfThree(int n) {
        return f(n);
    }
};

string base3(int num){
    if(num==0) return "0";
    string s;
    while(num>0){
        s.push_back((num%3)+'0');
        num/=3;
    }
    return s;
}
bool checkPowersOfThree(int n) {
    string temp=base3(n);
    for(int i=0;i<temp.size();i++){
        if(temp[i]=='2') return false;
    }
    return true;
}

int main() {
    return 0;
}