# [1183. Maximum Number of Ones(hard)](https://leetcode.com/problems/maximum-number-of-ones/description/)

## Thoughts 
Didn't solve myself. Looked at solution. 
## Solution 1: Greedy
Main observation is that once you fill out the first sub-square that is sideLength*sideLength, you can translate that square through the grid to ensure that maxOnes is correct for each subsquare. For example, if you filled out the topleft sub-square, then you consider subsquare 1 column to the right, you need the num ones in first column for this square. Thus just translate the first column to the rightmost column of subsquare. Therefore, all you need to do is fill out the first subsquare optimally. To do that we calculate how many times the relative position of the square will repeat through the grid.
```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-ones/
// Author: https://github.com/spookyflame10
// Time: O(sideLength^2*log*sideLength^2)
// Space: O(sideLength^2)
class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        if(maxOnes==0) return 0;
        if(maxOnes == sideLength*sideLength) return width*height;
        if(sideLength==1) return width*height;
        vector<int> counts;
        for(int i=1; i<=sideLength; i++){
            for(int j=1; j<=sideLength; j++){
                counts.push_back(((width-j)/sideLength+1)*((height-i)/sideLength+1));
            }
        }
        sort(counts.begin(), counts.end(), greater<int>()); //reverse(counts);
        int ans =0;
        for(int i=0; i<maxOnes; ++i){
            ans+=counts[i];
        }
        return ans;
    }
};
```
## Solution 2: Greedy
You can also do it in O(1). 