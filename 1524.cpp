/*

1524. Number of Sub-arrays With Odd Sum
Given an array of integers arr, return the number of subarrays with an odd sum.
Since the answer can be very large, return it modulo 109 + 7.

Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.
Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16

*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int total_num_of_subarray_with_odd_sum(vector<int>&arr){
    long even_cnt=0,odd_cnt=0;
    long prefix=0;
    long ans=0;
    for(auto it: arr) {
        prefix += it;
        if(prefix&1){
            ans += even_cnt+1;
            odd_cnt++;
        }
        else{
            ans += odd_cnt;
            even_cnt++;
        }
    }
    return ans % MOD;
}

// xor solution
int total_num_of_subarray_with_odd_sum_xor(vector<int>&arr){
    bool is_sum_odd=0;
    int parity[2]={1, 0};
    long ans=0;
    for(auto it: arr){
        is_sum_odd ^= it&1;
        ans+=parity[1-is_sum_odd];
        parity[is_sum_odd]++;
    }
    return ans % MOD;
}

int main() {
    return 0;
}