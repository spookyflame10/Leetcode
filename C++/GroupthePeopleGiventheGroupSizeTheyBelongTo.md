# [1282. Group the People Given the Group Size They Belong To](https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/?envType=daily-question&envId=2023-09-11)

## Thoughts:
Prob should do this tmmrw, 12 rn.
## Solution 1: Greedy
Sort then make groups according to size. just keep on pushing into current group based on size.
```cpp
// OJ: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/?envType=daily-question&envId=2023-09-11
// Author: https://github.com/spookyflame10
// Time: O(Nlogn) sorting
// Space: O(n). space to map size to indicy
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<pair<int, int>> groups(n);
        for(int i=0; i<n; i++){
            groups[i] = {groupSizes[i],i};
        }
        sort(groups.begin(), groups.end());
        int i=0;
        vector<vector<int>> res;
        while(i<groupSizes.size()){
            int j=0; int size = groups[i].first;
            vector<int> cur;
            while(j<size){
                cur.push_back(groups[i].second);
                j++;
                i++;
            }
            res.push_back(cur);
        }
        return res;
    }
};
```
## Solution 1: Greedy
Simpler way: we don't have to sort, just go through array and increase size of group by 1 person and put into res when it reaches size.
```cpp
// OJ: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/?envType=daily-question&envId=2023-09-10
// Author: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/solutions/516968/java-c-python-easy-and-concise/?envType=daily-question&envId=2023-09-10
// Time: O(n): go through array once
// Space: O(1): storage for temp_group. 
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> temp_group; // map size to vector of people
        vector<vector<int>> result;
        
        for(int i = 0; i < groupSizes.size(); ++i) {
            int size = groupSizes[i];
            temp_group[size].push_back(i); // pushes person into group size
            
            if(temp_group[size].size() == size) { //if group_size is equal to size
                result.push_back(temp_group[size]);
                temp_group[size].clear();//clear
            }
        }
        return result;
    }
};
//interesting way to map in official solution, each indicy is an array.:         // A map from group size to the list of indices that are there in the group.
        // vector<int> szToGroup[groupSizes.size() + 1];
```