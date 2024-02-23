// Time  Complexity : O(V + E)
// Space Complexity : O(V)

// Problem Link : https://leetcode.com/problems/cheapest-flights-within-k-stops/description/?envType=daily-question&envId=2024-02-23

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        
        int m = flights.size();
        
        for(int i = 0 ; i < m ; i++)    {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v , wt});
        }
        k++;
        
        vector<int> dist(n , INT_MAX);
        
        dist[src] = 0;
        queue<pair<pair<int,int> , int>> q;
        
        q.push({{src , 0} , 0});
        
        while(!q.empty()) {
            int currNode = q.front().first.first;
            int currDist = q.front().first.second;
            int currStops = q.front().second;
            
            q.pop();
            
            if(currStops == k) 
                continue;
            
            for(pair<int,int> &neigh : adj[currNode]) {
                int nextNode = neigh.first;
                int totalWt = currDist + neigh.second;
                
                if(totalWt < dist[nextNode]) {
                    dist[nextNode] = totalWt;
                    q.push({{nextNode , totalWt} , currStops+1});
                }
            }
        }
        
        if(dist[dst] == INT_MAX)
            return -1;
        
        return dist[dst];
    }
};