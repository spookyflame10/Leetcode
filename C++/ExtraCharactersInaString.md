# [2707. Extra Characters in a String(Medium)](https://leetcode.com/problems/counting-bits/description/?envType=daily-question&envId=2023-09-01)

## Thoughts 
Solved it sometime before. Interesting bit manipulation and dp.
## Solution 1: Pop Count
You can use __builtin_popcount(int number); funciton for each i. Or implement it yourself using j&(j-1) which will zero out the least significant bit. This might not be intuitive, so I encourage you to try it out with some examples.
```cpp
// OJ: https://leetcode.com/problems/counting-bits/editorial/?envType=daily-question&envId=2023-09-01
// Author: https://github.com/spookyflame10
// Time: O(n*logn) for each integer i we perform log(i) operations to get bit count
// Space: O(1) since output array doesn't count toward space complexity.
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=1; i<=n; i++){
            int j=i;
            while(j!=0){
                ans[i]++;
                j&=(j-1);
            }
        }
        return ans;
    }
};
```
### Using __builtin_popcount(i);
```cpp
// OJ: https://leetcode.com/problems/counting-bits/editorial/?envType=daily-question&envId=2023-09-01
// Author: https://github.com/spookyflame10
// Time: O(n*logn) for each integer i we perform log(i) operations to get bit count
// Space: O(1) since output array doesn't count toward space complexity.
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=1; i<=n; i++)
            ans[i] = __builtin_popcount(i);
        return ans;
    }
};
```
## Solution 2: DP
Let ans[i] = popcount of number i. Then ans[i] = ans[i&(i-1)]+1. In other words, popcount of i equals to the number i with the lsb(least significant bit) removed + 1.
```cpp
// OJ: https://leetcode.com/problems/counting-bits/editorial/?envType=daily-question&envId=2023-09-01
// Author: https://github.com/spookyflame10
// Time: O(n*logn) for each integer i we perform log(i) operations to get bit count
// Space: O(1) since output array doesn't count toward space complexity.
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=1; i<=n; i++){
            ans[i] = ans[i&(i-1)]+1;
        }
        return ans;
    }
};
```