#include <bits/stdc++.h>
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing = true;
        bool isDecreasing = true;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]>nums[i]) isIncreasing = false;
            if(nums[i-1]<nums[i]) isDecreasing = false;
        }
        return isIncreasing |isDecreasing;
    }
};