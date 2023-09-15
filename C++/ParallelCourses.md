# [1136. Parallel Courses](https://leetcode.com/problems/parallel-courses/description/)

## Problem
In this problem, we find out the number of semesters it takes to complete a courses where you can't take a course until you finish taking all the prerequisites. You can take any amount of courses as long as you take the prerequisites, and if there is a cycle(all courses have at least one prerequisite) then return -1;
## Solution 1: Kahn's algo
The number of semestes is  height of the tree.
Essentially Kahn's algo is this: You visit all nodes of indegree zero and subtrack 1 from the indegree of all it's children. You then visit the children who has indegree zero. You keep on going until queue is empty.    
To deal with cycles : if visit size is less than all nodes then there is a cycle. This is because we only visit nodes with indegree  zero and cycles never have indegree zero. I don't need a visited vector because I already know that we can't push any cycle nodes into the queue
```cpp
// OJ: https://leetcode.com/problems/parallel-courses/description/
// Author: https://github.com/spookyflame10
// Time: O(N+E): bfs takes N+E because we visit all nodes and edges atmost once.
// Space: O(N+E): the graph data structure stores N keys and E values.
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> graph(n+1);
        vector<int> indegree(n+1,0);// maps node to its indegree.
        for(auto e: relations){
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        int numNodesVisited =0;
        queue<int> q;
        for(int i=1; i<n+1; i++){
            if(indegree[i]==0){
                q.push(i); 
            } 
        }
        int ans =0;
        while(!q.empty()){
            ans++;
            for(int i=q.size(); i>=1; i--){
                numNodesVisited++;
                int s = q.front(); q.pop();
                for(auto v:graph[s]){
                    indegree[v]--;
                    if(indegree[v]==0)
                        q.push(v);
                }
            }
        }
        if(numNodesVisited!=n) return -1;
        return ans;
    }
};
```
## Solution 2: Depth-First Search: Combine
Main observation is that the number of semesters is equal to the longest path in the graph. You can think that because this is the longest sequeuce of prerequisites. Now you can just find the longest path and make sure to detect cycles. 
```cpp
// Author(not me): https://leetcode.com/problems/parallel-courses/solutions/345015/c-dfs-15-line-and-bfs-15-line/
// Time: O(N+E): bfs takes N+E because we visit all nodes and edges atmost once.
// Space: O(N+E): the graph data structure stores N keys and E values.
    int minimumSemesters(int N, vector<vector<int>>& relations)
    {
        vector<int> vDepth(N, 1), visitState(N, 0); // visite state  -1 :visiting;  0:not visit;  1:visited
        vector<vector<int>> g(N);
        for (auto& v : relations) g[v[0] - 1].push_back(v[1] - 1); // making graph
        for (int i = 0; i < N; i++) if (!dfs(i, g, vDepth, visitState)) return -1; //check cycle starting from all nodes
        return *max_element(vDepth.begin(), vDepth.end());// returns max of depth
    }

    // return false if there is a circle
    bool dfs(int i, const vector<vector<int>> & g, vector<int> & vDepth, vector<int> & visitState) {
        if (visitState[i] == 1) return true;
        if (visitState[i] == -1) return false; // circle  
        visitState[i] = -1; //visiting
        for (auto j : g[i]) {
            if (!dfs(j, g, vDepth, visitState)) return false;
            vDepth[i] = max(vDepth[i], 1 + vDepth[j]);//set depth of cur node. 
        }
        visitState[i] = 1; //visited;
        return true;
    }
```
