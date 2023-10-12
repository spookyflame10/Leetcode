# [1063. Number of Valid Subarrays](https://leetcode.com/problems/number-of-valid-subarrays/description/)

## Problem
Given an integer array nums, return the number of non-empty subarrays with the leftmost element of the subarray not larger than other elements in the subarray.

A subarray is a contiguous part of an array.
## Solution 1: Monotonic Stack
The number of subarrays starting from an element is the size of the largest possible subarray. For example: {1, 2, 4} has 3 subarrays: {1}, {1,2}, {1,2,4}.
Therefore, for each element i, we just find an element to the right that's smaller than nums[i]. To efficiently find this element, we use a monotonic increasing stack so that the smallest element is always on top. Then the size of the subarray is just rightmost element - i.
```cpp
// OJ: https://leetcode.com/problems/number-of-valid-subarrays/description/
// Author: https://github.com/spookyflame10
// Time: O(N): One array pass
// Space: O(N): stack storage
int validSubarrays(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    int res =0;
    for(int i=n-1; i>=0; i--){
        while(!st.empty()&&nums[st.top()]>=nums[i]) st.pop(); // take out all elements >= than nums[i] on the stack. that way an element smaller than nums[i] will be on the stack, and since we go in order, this element is the leftmost smallest.(leftmost always on top of the stack).
        if(st.empty()) res+=n-i;
        else res+=st.top()-i;
        st.push(i);
    }   
    return res;
}
```
## Solution 2: Another way to think about it
Maintain a monotonic stack, when we're at number curr, each number num in the stack is the starting number such that [num, curr] can form a valid subarray. So the size of stack is the number of valid subarrays that end at curr.
e.g., [1, 4, 2, 5, 3]
curr = 1, stack = [1] -> valid subarray is [1]
curr = 4, stack = [1, 4] -> valid subarrays are [1, 4], [4]
curr = 2, stack = [1, 2] -> valid subarrays are [1, 4, 2], [2]
curr = 5, stack = [1, 2, 5] -> valid subarrays are [1, 4, 2, 5,], [2, 5], [5]
curr = 3, stack = [1, 2, 3] -> valid subarrays are [ 1, 4, 2, 5, 3], [2, 5, 3], [3]
```cpp
// OJ: https://leetcode.com/problems/number-of-valid-subarrays/description/
// Author: https://leetcode.com/problems/number-of-valid-subarrays/solutions/314317/c-o-n-stack/
// Time: O(N): One array pass
// Space: O(N): stack storage
int validSubarrays(vector<int>& nums, int res = 0) {
  vector<int> s;
  for (auto n : nums) {
    while (!s.empty() && n < s.back()) s.pop_back();
    s.push_back(n);
    res += s.size();
  }
  return res;
}
```
