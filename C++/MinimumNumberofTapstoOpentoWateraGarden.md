# [1326. Minimum Number of Taps to Open to Water a Garden(hard)](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/)

There is a one-dimensional garden on the x-axis. The garden starts at the point `0` and ends at the point `n`. (i.e The length of the garden is `n`).

There are `n + 1` taps located at points `[0, 1, ..., n]` in the garden.

Given an integer `n` and an integer array `ranges` of length `n + 1` where `ranges[i]` (0-indexed) means the `i-th` tap can water the area `[i - ranges[i], i + ranges[i]]` if it was open.

Return *the minimum number of taps* that should be open to water the whole garden, If the garden cannot be watered return **-1**.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/01/16/1685_example_1.png)

**Input:** n = 5, ranges = [3,4,1,1,0,0]
**Output:** 1
**Explanation:** The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]

**Example 2:**

**Input:** n = 3, ranges = [0,0,0,0]
**Output:** -1
**Explanation:** Even if you activate all the four taps you cannot water the whole garden.

**Constraints:**

-   `1 <= n <= 104`
-   `ranges.length == n + 1`
-   `0 <= ranges[i] <= 100`

## Solution 1 (My Greedy Way)
Use Greedy. First get intervals. Then sort the intervals first by min left second by max right. Then go through the sorted intervals starting from the smallest one, you choose this interval. In the loop: you choose the interval with the largest right for all intervals with left within the current right. Keep track of count of intervals you choose in ans variable. Keep on going until right >=n.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
// Author: https://github.com/spookyflame10
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> intervals;
        for(int i=0; i<ranges.size(); i++){
            intervals.push_back({(i-ranges[i])<0?0:i-ranges[i], i+ranges[i]});
        }
        sort(intervals.begin(), intervals.end(), [](pair<int, int>&a, pair<int, int>&b){
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first<b.first;
        });
        int ans =1;
        int i=0;
        int right =intervals[0].second;
        while(right<n){
            int biggest = 0;
            while(i<=n&&intervals[i].first<=right){
                biggest = max(biggest, intervals[i].second);
                i++;
            }
            if(biggest ==0) return -1;
            right = biggest;
            ans++;
        }
        return ans;
    }
};
```
## Official LeetCode Solutions
## Solution 2: Dynamic Programming
let dp[i] represent the min. number of taps needed to water the garden from position 0 to position i.  
Base Case: dp[0] =0, because we don't have to open any taps to water 0 length.  
Transition State: dp[tapEnd]=min(dp[tapEnd], dp[j]+1) where tapStart<=j<=tapEnd and tapStart = i-ranges[i] and tapEnd = i+ranges[i]. 


```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
// Author: LeetCode
// Time: O(n⋅m).
// Space: O(N)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // Define an infinite value
        const int INF = 1e9;
        // Create a vector to store the minimum number of taps needed for each position
        vector<int> dp(n + 1, INF);

        // Initialize the starting position of the garden
        dp[0] = 0;
        
        for (int i = 0; i <= n; i++) {
            // Calculate the leftmost position reachable by the current tap
            int tapStart = max(0, i - ranges[i]);
            // Calculate the rightmost position reachable by the current tap
            int tapEnd = min(n, i + ranges[i]);
            
            for (int j = tapStart; j <= tapEnd; j++) {
                // Update with the minimum number of taps
                dp[tapEnd] = min(dp[tapEnd], dp[j] + 1);
            }
        }
        
        // Check if the garden can be watered completely
        if (dp[n] == INF) {
            // Garden cannot be watered
            return -1;
        }
        
        // Return the minimum number of taps needed to water the entire garden
        return dp[n];
    }
};
```
## Solution 3: Better Greedy
Similar solution to Jump Game 3. Let max_reach[i] be the maximum end over all taps having start =i. 
  Amoung the taps that have start<=currEnd we choose next_end -max end over these taps.  
  we can simplify by making next_end = max_reach[i] for all i<=curr_end.


```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
// Author: LeetCode
// Time: O(n).
// Space: O(N)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // Create a vector to track the maximum reach for each position
        vector<int> maxReach(n + 1);

        // Calculate the maximum reach for each tap
        for (int i = 0; i < ranges.size(); i++) {
            // Calculate the leftmost position the tap can reach
            int start = max(0, i - ranges[i]);
            // Calculate the rightmost position the tap can reach
            int end = min(n, i + ranges[i]);

            // Update the maximum reach for the leftmost position
            maxReach[start] = max(maxReach[start], end);
        }
        
        // Number of taps used
        int taps = 0;
        // Current rightmost position reached
        int currEnd = 0;
        // Next rightmost position that can be reached
        int nextEnd = 0;

        // Iterate through the garden
        for (int i = 0; i <= n; i++) {
            // Current position cannot be reached
            if (i > nextEnd) {
                return -1;
            }

            // Increment taps when moving to a new tap
            if (i > currEnd) {
                taps++;
                // Move to the rightmost position that can be reached
                currEnd = nextEnd;
            }

            // Update the next rightmost position that can be reached
            nextEnd = max(nextEnd, maxReach[i]);
        }

        // Return the minimum number of taps used
        return taps;
    }
};
```