# [2393. Count Strictly Increasing Subarrays](https://leetcode.com/problems/count-strictly-increasing-subarrays/description/)

## Problem
In a array nums, consisting of positive integers, return the number of subarrays of nums that are in strictly increasing order.
## Solution 1: DP
Let subarraySize(i) represent the size of an strictly increasing subarray ending at index i. Idea: the number of strictly increasing subarrays that will be added with an additional element is 1 if the additional element is <= prev, or the subarraySize(i). Therefore we can just go through array and add the number of subarrays we can get for each additional element.
```cpp
// OJ: https://leetcode.com/problems/count-strictly-increasing-subarrays/description/
// Author: https://github.com/spookyflame10
// Time: O(N): One array pass
// Space: O(N): dp array
class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> subarraySize(n, 1);
        long long ans=1;
        for(int i=1; i<n; i++){
            if(nums[i-1]<nums[i]){
                subarraySize[i]= subarraySize[i-1]+1;
                ans+=subarraySize[i];
            } else ans+=1;
        }
        return ans;
    }
};
```
## Solution 2: Optimizations
You can optimize previous solution to have O(1) space. You can also use sum formula for increasing sequence and find length of curSubarray using while loop.
```cpp
// OJ: https://leetcode.com/problems/count-strictly-increasing-subarrays/description/
// Author: https://github.com/spookyflame10
// Time: O(N): One array pass
// Space: O(1): dp array
class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int curSubarray =1;
        long long ans=1;
        for(int i=1; i<n; i++){
            if(nums[i-1]<nums[i])
                curSubarray++;
            else curSubarray=1;
            ans+=curSubarray;
        }
        return ans;
    }
};
```
