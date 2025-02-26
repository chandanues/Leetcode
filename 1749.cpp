/*

1749. Maximum Absolute Sum of Any Subarray

You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.

*/

#include <bits/stdc++.h>
using namespace std;

int maximum_absolute_subarray(vector<int>&nums){
    int n=nums.size();
    int curr_maxi_sum=0, curr_mini_sum=0;
    int global_maxi_sum=INT_MIN, global_mini_sum=INT_MAX;

    for(int i=0;i<n;i++) {
        curr_maxi_sum+=nums[i];
        if(curr_maxi_sum<0) curr_maxi_sum=0;
        global_maxi_sum=max(global_maxi_sum, curr_maxi_sum);

        curr_mini_sum+=nums[i];
        if(curr_mini_sum>0) curr_mini_sum=0;
        global_mini_sum=min(global_mini_sum, curr_mini_sum);
    }

    return max(abs(global_maxi_sum), abs(global_mini_sum));
}

int main() {
    return 0;
}