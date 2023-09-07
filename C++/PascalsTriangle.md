# [118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/description/?envType=daily-question&envId=2023-09-08)

## Solution 1: Dynamic Programming
currentRow[j] = prevRow[j-1]+prevRow[j] where 1<=j<size(curRow). You can see this form Pascal's triangle.
```cpp
// OJ: https://leetcode.com/problems/pascals-triangle/description/?envType=daily-question&envId=2023-09-08
// Time: O(n^2) because for each current row, you have to go through previous row which could be numRows length long.
// Space: O(1) we don't count output which is numRows^2 size.
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for(int i=0; i<numRows; i++){
            res[i].resize(i+1); //each row of pascals increase by 1
            res[i][0]=res[i][i] = 1;
            for(int j=1; j<i; j++){
                res[i][j]=res[i-1][j-1]+res[i-1][j];
            }
        }
        return res;
    }
};
```