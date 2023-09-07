# [358. Rearrange String k Distance Apart](https://leetcode.com/problems/rearrange-string-k-distance-apart/description/)
## Thoughts
Took forever to solve. Had to look. Need to get better at these types.
## Solution 1: Priority_Queue
All characters between indices x and x+k must be unique. We greedily get the character with max_freq from priority_queue. After adding to result string, we push this to the waiting queue where it must wait for k indices. We keep track of indices by pushing the current indicie(size of res) into waiting and popping from waiting if current index-waiting.front()[2]>=k. ie curIndex-prevIndex>=k. Note that waiting is first in first out(queue) so getting the front of queue would work.
```cpp
// OJ: https://leetcode.com/problems/pascals-triangle/description/?envType=daily-question&envId=2023-09-08
// Time: O((N+K)logk) where N is number of chars in S and k is number of unique chars in S. kinda O(N) because k is 26 at max. pq is max size k. making res O(Nlogk). Initializing waiting is O(KlogK).
// Space: O(K). size of mp, waiting, pq is at worst k.
class Solution {
public:
    string rearrangeString(string s, int k) {
        priority_queue<pair<int, char>> pq;
        queue<vector<int>> waiting;
        map<char, int> mp;
        for(auto c: s) mp[c]++;
        for(auto p: mp) pq.push({p.second, p.first});
        string res;
        while(res.size()!=s.size()){
            int index = res.size();
            // get character from waiting if we can
            if(!waiting.empty()&&(index-waiting.front()[2]>=k)){
                vector<int> w = waiting.front(); waiting.pop();
                pq.push({w[0], w[1]});
            }
            // if pq is empty then not possible
            if(pq.empty()) return "";
            pair<int, char> p = pq.top(); pq.pop();
            if(p.first>1){
                waiting.push({p.first-1, p.second,index });
            }
            res+=p.second;  
        }
        return res;
    }
};
```
## Solution 2: Greedy
Use Round-Robin strategy(not official). putting max freq chars in k length segments. See [editorial](https://leetcode.com/problems/rearrange-string-k-distance-apart/editorial/). Time:O(N). Space(O(K)).