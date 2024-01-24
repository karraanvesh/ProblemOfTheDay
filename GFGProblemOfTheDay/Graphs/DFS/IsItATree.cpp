// Time Complexity  : O(n + m)
// Space Complexity : O(n) + O(n + m) (for auxilary stack space)
// where n and m are the number of nodes and edges in a graph

// Problem Link : https://www.geeksforgeeks.org/problems/is-it-a-tree/1

class Solution {
    private:
    bool dfs(vector<int> adj[] , int node , int parent , vector<bool> &visited) {
        visited[node] = true;
        
        for(int &neigh : adj[node]) {
            
            if(neigh == parent)
            continue;
            
            if(visited[neigh])
            return true;
            
            else {
                if(dfs(adj , neigh , node , visited))
                return true;
            }
        }
        
        return false;
    }
  public:
    int isTree(int n, int m, vector<vector<int>> &edges) {
        vector<int> adj[n];
        set<pair<int,int>> st;
        
        for(int i = 0 ; i < m ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            pair<int , int> p;
            
            if(v > u) {
                swap(u , v);
            }
            
            p.first = u;
            p.second = v;
            
            if(st.count(p) != 0) return 0;
            
            st.insert(p);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(n , false);
        int componentCount = 0;
        
        for(int i = 0 ; i < n ; i++) {
            
            if(!visited[i]) {
                componentCount++;
                bool result = dfs(adj , i , -1 , visited);
                
                if(result)
                return 0;
            }
        }
        
        if(componentCount == 1)
        return 1;
        
        return 0;
    }
};