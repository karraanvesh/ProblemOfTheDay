// Time Complexity : O(V + E)
// Space Complexity : O(V + 2*E) + O(V) (for auxilary stack space)

class Solution {
    private :
    bool dfs(vector<int> adj[] , vector<bool> &visited , int node , int dest) {

        if(node == dest) return true;

        visited[node] = true;

        for(int &neigh : adj[node]) {

            if(!visited[neigh]) {

                if(dfs(adj , visited , neigh , dest))
                return true;
            }
        }

        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];

        int m = edges.size();

        for(int i = 0 ; i < m ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n , false);
        if(dfs(adj , visited , source , destination))
        return true;

        return false;
    }
};