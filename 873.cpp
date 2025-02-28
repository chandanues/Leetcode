/*

873. Length of Longest Fibonacci Subsequence
A sequence x1, x2, ..., xn is Fibonacci-like if:

n >= 3
xi + xi+1 == xi+2 for all i + 2 <= n
Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.

A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].

 

Example 1:

Input: arr = [1,2,3,4,5,6,7,8]
Output: 5
Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
Example 2:

Input: arr = [1,3,7,11,12,14,18]
Output: 3
Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].
 

Constraints:
3 <= arr.length <= 1000
1 <= arr[i] < arr[i + 1] <= 109

*/

#include <bits/stdc++.h>
using namespace std;

int lenLongestFibSubseq(vector<int>& arr) {
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    int longest=0;
    for(int sum=2;sum<n;sum++){
        int a=0;
        int b=sum-1;
        while(a<b){
            if(arr[a]+arr[b]<arr[sum]) a++;
            else if(arr[a]+arr[b]>arr[sum]) b--;
            else{
                dp[b][sum]=1 + dp[a][b];
                longest=max(longest,dp[b][sum]);
                a++;b--;
            }
        }
    }
    return longest==0?0:2+longest;
}

int f(vector<int>&arr,int x,int y,int n){
        int lb_idx=lower_bound(arr.begin(),arr.end(),x+y)-arr.begin();
        if(lb_idx<n&&arr[lb_idx]==x+y){
            return 1+f(arr,y,x+y,n);
        }
        return 0;
    }
    int lenLongestFibSubseq__(vector<int>& arr) {
        int n=arr.size();
        int longest=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int x=arr[i];
                int y=arr[j];
                int fib_len=f(arr,x,y,n);
                if(fib_len>0) longest=max(longest,fib_len);
            }
        }
        return longest==0?0:longest+2;
}

int lenLongestFibSubseq_(vector<int>& arr) {
        unordered_set<int>st(arr.begin(),arr.end());
        int len=arr.size();
        int longest=0;
        for(int i=0;i<len-1;i++){
            for(int j=i+1;j<len;j++){
                int a=arr[i];
                int b=arr[j];
                int fiblen=2;
                while(st.count(a+b)>0){
                    int sum=a+b;
                    a=b;
                    b=sum;
                    fiblen++;
                }
                if(fiblen>2){
                    longest=max(longest,fiblen);
                }
            }
        }
        return longest;
    }

int main() {
    return 0;
}