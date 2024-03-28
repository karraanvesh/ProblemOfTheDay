// Time  Complexity : O(V * (V + ElogE))
// Space Complexity : O(V + 2 * E)

// Problem Link : https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1

class Solution {
    private :
    int dijkstrasAlgo(vector<pair<int , int>> adj[] , int node , int n , 
    int distanceThreshold) {
        
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        
        pq.push({0 , node});
        
        vector<int> dist(n , INT_MAX);
        dist[node] = 0;
        int result = 0;
        
        while(!pq.empty()) {
            int currNode = pq.top().second;
            int weight = pq.top().first;
            
            pq.pop();
            
            for(pair<int , int> &neigh : adj[currNode]) {
                int nextNode = neigh.first;
                int cost = neigh.second;
                
                if((weight + cost) <= distanceThreshold and (weight + cost) <= dist[nextNode]) {
                    dist[nextNode] = weight + cost;
                    pq.push({weight + cost , nextNode});
                }
            }
        }
        
        for(int i = 0 ; i < n ; i++) {
            if(dist[i] != INT_MAX)
            result++;
        }
        
        return result;
    }
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int , int>> adj[n];
        
        for(int i = 0 ; i < m ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
        }
        
        int minNeighbours , node = 0;
        minNeighbours = INT_MAX;
        for(int i = 0 ; i < n ; i++) {
            
            int numberOfNeighbours = dijkstrasAlgo(adj , i , n , distanceThreshold);
            
            if(numberOfNeighbours <= minNeighbours) {
                node = i;
                minNeighbours = numberOfNeighbours;
            }
        }
        
        return node;
    }
};