// Time Complexity : O(V + E)
// Space Complexity : O(V + 2*E) (for adjacency list)
// where V are the vertices and E are the number of edges in the graph 

// Problem Link : https://www.geeksforgeeks.org/problems/course-schedule/1

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> adj[n];
        vector<int> indegree(n , 0);
        
        for(int i = 0 ; i < m ; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> q;
        vector<int> topoSort;
        
        for(int i = 0 ; i < n ; i++) {
            
            if(indegree[i] == 0) {
                q.push(i);
                topoSort.push_back(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(int &neigh : adj[node]) {
                
                indegree[neigh]--;
                
                if(indegree[neigh] == 0) {
                    q.push(neigh);
                    topoSort.push_back(neigh);
                }
            }
        }
        
        if(topoSort.size() != n) {
            topoSort.resize(0);
        }
        
        return topoSort;
        
    }
};