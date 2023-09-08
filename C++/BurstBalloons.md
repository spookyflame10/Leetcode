# [312. Burst Balloons](https://leetcode.com/problems/burst-balloons/description/)

## Thoughts:
Great problem. Didn't do myself. Insane solution
## Solution 1: Top-Down Dynamic Programming
Naive way is to go through all subsets which is 2^n.   
Dp time complexity is divided into number of states and time spent on each state. We can decrease time complexity by decreasing number of states and decreasing time spent on each state. If we burst balloon in middle then it divides into 2 subarrays and then we can combine results together.(divide and conquer)
  
Let dp(left, right) represent the max coins obtainable after bursting all baloons from [left, right] in some order. To make dp calls independent we think of which baloon to burst last.
base case is interval empty: return 0.
For general cases we iterate over every index i in [left,right] and mark balloon as the last one burst. First we burst all balloons expect the ith one: we gain dp(left, i-1)+dp(i+1, right). Then we burst the ith one. return dp(1, len(dp)-2).
```cpp
// OJ: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/?envType=daily-question&envId=2023-09-11
// Author: https://github.com/spookyflame10
// Time: O(n^3) states is N^2 and each state takes O(N)
// Space: O(N^2) to store states
class Solution {
public:
    int solve(vector<int>& nums,vector<vector<int>>& memo, int left, int right){
        if(left>right) return 0; //inclusive
        if(memo[left][right]>=0) return memo[left][right];
        int res =0;
        
        for(int i=left; i<=right; i++){
            int curCoins =solve(nums,memo,left, i-1)+solve(nums,memo,i+1, right);
            curCoins+=nums[i]*nums[left-1]*nums[right+1];//burst balloon after bursting all the other balloons. So that we can make recursive calls independent from each other.
            res = max(res, curCoins);
        }
        return memo[left][right] = res;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), -1)); // maps range to max coins you can get after bursting all the balloons
        return solve(nums, memo, 1, nums.size()-2);
    }
};
```
