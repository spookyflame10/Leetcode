# [377. Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/description/?envType=daily-question&envId=2023-09-09)

## Solution 1: Top Down DP
Let dp(i) = # of possible combination for target-i.
Recurrence Relation: dp(i)=dp(i+j) for all j in nums.
Base: i==target: return 1(1 way). i>target: return 0.
```cpp
// OJ: https://leetcode.com/problems/combination-sum-iv/description/?envType=daily-question&envId=2023-09-09
// Author: https://github.com/spookyflame10
// Time: O(TN) T(target) possible states and for each state we go through nums(length N)
// Space: O(T). We store target states in memo array
class Solution {
public:
    int target;
    map<int, int> memo; 
    int backtrack(vector<int>& nums, int sum){
        if(sum==target) return 1;
        if(sum>target) return 0;
        if(memo.count(sum)) return memo[sum];
        int numComb =0;
        for(int i=0; i<nums.size(); i++){
            numComb += backtrack(nums, sum+nums[i]);
        }
        return memo[sum] = numComb;
    }
    int combinationSum4(vector<int>& nums, int target) {
        this->target = target;
        return backtrack(nums, 0);// dp. dp[i] = # comb for target-i
    }
};
```
## Solution 1: Bottom Up DP
Let dp(i) = # of possible combination for sum i
Recurrence Relation: dp(i)=dp(i-j) for all j in nums.
Base: i==0: return 1 because there is 1 way to form 0(not using anything).
```cpp
// OJ: https://leetcode.com/problems/combination-sum-iv/description/?envType=daily-question&envId=2023-09-09
// Author: https://github.com/spookyflame10
// Time: O(TN) T(target) possible states and for each state we go through nums(length N)
// Space: O(T). We store target states in memo array
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1,0);
        dp[0]=1;
        for(int sum =1; sum<target+1; sum++){
            for(int num:nums){
                if(sum-num>=0)
                  dp[sum]+=dp[sum-num];  
            }
        }
        return dp[target];
    }
};
```