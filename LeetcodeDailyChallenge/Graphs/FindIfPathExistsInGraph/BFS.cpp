// Time  Complexity : O(V + E)
// Space Complexity : O(V + 2*E)

class Solution {
    private :
    bool bfs(vector<int> adj[] , vector<bool> &visited , int node , int dest) {

        queue<int> q;
        q.push(node);

        visited[node] = true;

        while(!q.empty()) {
            int node = q.front();

            q.pop();

            if(node == dest) return true;

            for(int &neigh : adj[node]) {

                if(!visited[neigh]) {
                    q.push(neigh);
                    visited[neigh] = true;
                }
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
        if(bfs(adj , visited , source , destination))
        return true;

        return false;
    }
};