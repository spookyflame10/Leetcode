# [135. Candy](https://leetcode.com/problems/candy/description/?envType=daily-question&envId=2023-09-13)
## Problem
each child asigned a rating value. children with higher rating get MORE candies than neighbors. 
each child needs at least one candy. return min candies you need to distribute to children.
## Solution 1: Greedy and DP
peeks and valleys. greedy: every valley in array should be assigned a 1. 
only those with higher rating get more candy. thus same rating can have less.
1 2 2 3 2 2 1 = 1 2 1 2 1 2 1.
1 2 2 1 2 2 1 = 1 2 2 1 2 2 1
1 2 2 1 3 2 1 = 1 2 2 1 3 2 1. - 3 depends on largest increasing right. 
Main observation: We find largest decreasing subsequence form left and largest decreasing subsequence form right of number.
then we take max of those lengths to find the min candy to give to person i.
dp[i] is always atleast 1 because subsequence is atleast 1 term.
dp arrays: let left[i] = largest decreasing subsequence starting from i and going left
left[i] = (rating[i]>rating[i-1])?1+left[i-1]:1;
base case: left[0] = 1;
let right[i] = largest decreasing subsequence starting form i and going right
right[i] = (rating[i]>rating[i+1])?1+right[i+1]:1;
base case: right[ratins.size()-1] = 1;
Thus ans = sum of max(left[i], right[i]) for all i.
```cpp
// OJ: https://leetcode.com/problems/candy/description/?envType=daily-question&envId=2023-09-13
// Author: https://github.com/spookyflame10
// Time: O(n) only going through arrays 3 times
// Space: O(N) storage for dp arrays
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        for(int i=1; i<n; i++){
            left[i] = (ratings[i]>ratings[i-1])?1+left[i-1]:1;
        }
        for(int i=n-2; i>=0; --i){
            right[i] = (ratings[i]>ratings[i+1])?1+right[i+1]:1;
        }
        int ans =0;
        for(int i=0; i<n; i++){
            ans+=max(left[i], right[i]);
        }
        return ans;
    }
};
```
## One Pass O(1) space   
Not sure how this works. Will Probably never know LMAOOOO: 
https://leetcode.com/problems/candy/solutions/135698/Simple-solution-with-one-pass-using-O(1)-space/
