# [72. Edit Distance(medium)](https://leetcode.com/problems/edit-distance/description/)

## Thoughts 
One of those top-down dp problems. Similar to [Target Sum](https://leetcode.com/problems/target-sum/) and more.
This problem refers to Levenshtein distance. This distance finds edit distance allowing 3 operations: addition, deletion, removal.
## Solution 1: Top-Down Dp
States: dp[i][j] = min edit distance to convert i to end in word1 and j to end in word2. 
Recurrence Relation: if(word1[i]==word2[j]) then we can just go forward so return dp[i+1][j+1]. Otherwise, we try all 3 choices: addtion: dp[i][j+1], deletion: dp[i+1][j], removal: dp[i+1][j+1]. We take the min of these and add 1 because each takes one operation.
Base Cases: if(j==word2.size()) then best choice is to only insert letters into word1, so return word1.size()-i.
if(i==word1.size()) then best choice is to only delete characters from word1, so return word2.size()-j;
```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-ones/
// Author: https://github.com/spookyflame10
// Time: O(N*M) where N is word1.size() and M is word2.size()
// Space: O(N*M) dp array
class Solution {
public:
    int n, m;
    string word1, word2;
    int solve(int i, int j, vector<vector<int>>& dp){
        if(j==m) return n-i;//keep on deleting
        if(i==n) return m-j;//keep on inserting
        if(dp[i][j]) return dp[i][j];
        int ans =INT_MAX;
        if(word1[i]==word2[j]){
            ans=solve(i+1, j+1, dp);
        } else{
            ans=min(ans,solve(i,j+1, dp)+1); //insert an character
            ans = min(ans, solve(i+1, j, dp)+1);//delete an character
            ans= min(ans, solve(i+1, j+1, dp)+1);//replace an character
        }
        dp[i][j] = ans;
        return ans;
    }
    int minDistance(string word1, string word2) {
       n = word1.size(); m = word2.size();
       this->word1 = word1; this->word2 = word2;
       vector<vector<int>> dp(n, vector<int>(m, 0));//min number of operations to convert i to end in word1 and j to end in word2. 
       return solve(0,0,dp);
    }
};
```
## Solution 2: Bottom-Up Dp
You can also convert the top-down to bottom-up. Note, you can also make the space complexity O(N) because the current dp row only depends on the previous dp row.
```cpp
// Time: O(N*M) where N is word1.size() and M is word2.size()
// Space: O(N*M) dp array
class Solution {
public:
    int minDistance(string word1, string word2) {
       int n = word1.size(); int m = word2.size();
       vector<vector<int>> dp(n+1, vector<int>(m+1, 0));//min number of operations to convert 1 to i in word1 and 1 to j in word2. Assume 1-indexed. We do this so that dp[0][k] = k because 0-0 in word1 = empty string.
       for(int i=1; i<=n; i++) {
           dp[i][0] = i;
       } for(int j=1; j<=m; j++){
           dp[0][j] = j;
       }
       for(int i=1; i<=n; i++){
           for(int j=1; j<=m; j++){
               if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1]; //if equal we use previous edit distance
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;// otherwise we try out all 3, each one taking one operation
           }
       }
       return dp[n][m];
    }
};
```