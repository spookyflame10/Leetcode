// Time: O(n^2) traverses N^2 dp table
// Space: O(n^2) from dp table
#include <bits/stdc++.h>
class Solution {
public:
    int countSubstrings(string s) {
        int ans=0; int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n,false));// true if palindrome
        for(int i=n-1; i>=0; i--)//need to start from smallest difference to biggest because bigger difference relies on smaller one
            for(int j=i; j<n; j++)
                if(s[i]==s[j]&&((j-i<3)||dp[i+1][j-1])){
                  dp[i][j] = true; ans++;
                }
                    
        return ans;
    }
};