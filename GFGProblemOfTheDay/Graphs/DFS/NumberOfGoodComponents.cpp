// Time  Complexity : O(V + E)
// Space Complexity : O(V) + O(V) (for auxilary space)

// Problem Link : https://www.geeksforgeeks.org/problems/number-of-good-components--170647/1

class Solution {
    private :
    void dfs(int node , vector<int> adj[] , vector<bool> &visited , int &ct , 
    set<pair<int , int>> &st) {
        
        visited[node] = true;
        ct++;
        
        for(int &neigh : adj[node]) {
            int u = node;
            int v = neigh;
            
            pair<int , int> p;
            p.first = (u < v) ? u : v;
            p.second = (u > v ) ? u : v;
            
            
            if(st.count(p) == 0) {
                st.insert(p);
            }
            
            if(!visited[neigh]) {
                dfs(neigh , adj , visited , ct , st);
            }
        }
        
        return ;
    }
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        vector<int> adj[v + 1];
        
        for(int i = 0 ; i < e ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        vector<bool> visited(v + 1 , false);
        int result = 0;
        
        for(int i = 1 ; i <= v ; i++) {
            
            if(!visited[i]) {
                int ct = 0;
                set<pair<int , int>> st;
            
                dfs(i , adj , visited , ct , st);
                
                int goodComp = (ct * (ct - 1)) / 2;
                int size = st.size();
                
                if(goodComp == size)
                result++;
            }
        }
        
        return result;
    }
};