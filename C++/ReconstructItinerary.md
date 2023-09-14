# [332. Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/?envType=daily-question&envId=2023-09-14)

## Problem
In this problem, we reconstruct the airport path starting from "JFK". i.e. we must visit all the edges given only once.
## Solution 1: Backtracking
backtracking: explore all paths with airport with smallest lexical order picked first. finished when num nodes in path = num edges+1. Essentially we explore all path's starting from "JFK". We also make sure not to get into a cycle by having a visited map.
```cpp
// OJ: https://leetcode.com/problems/candy/description/?envType=daily-question&envId=2023-09-13
// Author: https://github.com/spookyflame10
// Time: O(E^D) where E is number of total flights(edges) and d is the maximum number of flights from an airport(degree). From each node we try all d edges if it's not visited
// Space: O(V+E) storage for dp arrays
class Solution {
public:
    int n;
    unordered_map<string, vector<string>> adj;
    unordered_map<string, vector<bool>> visited;
    vector<string> ans;
    bool backtrack(vector<string>& curPath, string curNode){
        if(curPath.size()==n+1){
          ans = curPath;
          return true;
        }
        vector<bool>& visit = visited[curNode];
        for(int i=0; i<visit.size(); i++){
          if(visit[i]==true) continue;
          visit[i] = true;
          curPath.push_back(adj[curNode][i]);
          if(backtrack(curPath, adj[curNode][i])) return true;
          visit[i] = false;
          curPath.pop_back();
        } 
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto x: tickets){
            adj[x[0]].push_back(x[1]);
        }
        n = tickets.size();
        for(auto& x: adj){
            sort(x.second.begin(), x.second.end());
            vector<bool> tmp(x.second.size());
            visited[x.first] = tmp;//make visited array all false.
        }
        vector<string> curPath;
        curPath.push_back("JFK"); 
        backtrack(curPath, "JFK");
        return ans;
    } 
};
```
## Solution 1: Hierholzer, DFS
hierholzer: dfs, put node in res once all its neighbors are visited. reverse res cause last node is put in first

```cpp
// OJ: https://leetcode.com/problems/reconstruct-itinerary/description/?envType=daily-question&envId=2023-09-14
// Author: https://github.com/spookyflame10
// Time: O(∣E∣log(E/V)) where E is number of total flights(edges) and d is the maximum number of flights from an airport(degree). From each node we try all d edges if it's not visited
// Space: O(V+E) storage for dp arrays
class Solution {
public:
    static vector<string> findItinerary(const vector<vector<string>>& tickets) {
        vector<string> ret;
        //appreant string_view is lighter and more performant then string. mainly used for printing string
        unordered_map<string_view, priority_queue<string_view, vector<string_view>, greater<>>> adj;
        for (auto& x : tickets)
            adj[x[0]].emplace(x[1]);
        
        function<void(string_view)> dfs = [&] (string_view curr) {
            auto& adj_nodes = adj[curr];
            while (!adj_nodes.empty()) { // go through all children
                auto temp = adj_nodes.top(); //get smallest lexcographically string
                adj_nodes.pop(); //remove edge
                dfs(temp);// go to next node
            }
            ret.emplace_back(curr); //once all neighbors are visited, then put in return.
        };

        dfs("JFK");
        reverse(begin(ret), end(ret));
        return ret;
    }
};
```
