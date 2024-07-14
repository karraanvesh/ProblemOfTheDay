// Time  Complexity : O(n * logm)
// Space Complexity : O(n + m)

// Problem Link : https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<pair<int , int>> adj[n + 1];
        
        for(int i = 0 ; i < m ; i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
        }
        
        vector<int> dist(n + 1 , INT_MAX);
        vector<int> parent(n + 1 , -1);
        
        int src = 1;
        
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        
        pq.push({0 , src});
        dist[src] = 0;
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int cost = pq.top().first;
            
            pq.pop();
            
            for(pair<int , int> &neigh : adj[node]) {
                
                int nextNode = neigh.first;
                int totalCost = cost + neigh.second;
                
                if(totalCost < dist[nextNode]) {
                    pq.push({totalCost , nextNode});
                    dist[nextNode] = totalCost;
                    parent[nextNode] = node;
                }
            }
        }
        
        vector<int> result;
        if(dist[n] == INT_MAX) {
           result.push_back(-1);
           
           return result;
        }
        
        int dest = n;
        
        while(parent[dest] != -1) {
            result.push_back(dest);
            
            dest = parent[dest];
        }
        
        result.push_back(dest);
        
        result.push_back(dist[n]);
        
        reverse(result.begin() , result.end());
        
        return result;
    }
};