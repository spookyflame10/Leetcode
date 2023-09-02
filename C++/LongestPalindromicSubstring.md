# [5. Longest Palindromic Substring(Medium)](https://leetcode.com/problems/longest-palindromic-substring/description/)

## Thoughts 
Great practice for Palindrome problems
## Solution 1: Dynamic Progrmaming
dp[i][j] = true if substring form i, j in string s is a palindrome.   
Recurrence Relation: if(s[i]==s[j]&&dp[i+1][j-1]==true) then dp[i][j] = true.
Base Cases: dp[i][i] = true. Because all substrings of length 1 are palindromes.  
Also all substrings of length 2 where both characters are equal are palindromes.
```cpp
// Time: O(n^2) we traverse through the dp table(n*n)
// Space: O(n^2) form dp table
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n+1, vector<bool> (n+1, false));// wheather  index i,j is a palindrome. 
        pair<int, int> ans={0,0};
        for(int i =n-1; i>=0; i--){ 
            for(int j=i; j<n; j++){ //going by smallest diff to largest makes it easier to find ans.
                dp[i][j] = s[i]==s[j]&&(j-i<3||dp[i+1][j-1]);// true if s[i]==s[j] and dp[i+1][j-1]
                if(dp[i][j]&&j-i>ans.second-ans.first) ans = {i, j}; // update ans if greater and i-j is palindrome
            }
        }
        return s.substr(ans.first, ans.second-ans.first+1);
    }
};
```

## Solution 2: 2 Pointers(Expanding from Center)
We have O(N) starting points. N starting points odd length palindromes and  N starting points for even length palindromes. We expand from these points using 2 pointers and get the largest possible palindrome from each point. Expansion is done if s[i]==s[j].
```cpp
// Time: O(n^2) It takes O(n) for each starting point so n*n
// Space: O(1) since we use no extra space.
class Solution {
public:
    int lo, maxLen;
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==1) return s;
        for(int i=0; i<n-1; i++){
            extend(s, i, i); //assume odd length palindrome, try to extend as much as possible
            extend(s, i, i+1);
        }
        return s.substr(lo, maxLen);
    }
    void extend(string s, int i, int j){
        while(i>=0&&j<s.length()&&s[i]==s[j]){
            i--; j++;
        }
        if(maxLen<j-i-1){
            maxLen = j-i-1; //because i and j is first invalid
            lo = i+1;
        }
    }

};
```
## Solution 3: Manacher's Algorithm
Can do in O(N) using [Manacher's algorithm](https://en.wikipedia.org/wiki/Longest_palindromic_substring#Manacher's_algorithm)