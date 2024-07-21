// Time  Complexity : O(n + m + 2 * k) ~ O(n + m + k)
// Space Complexity : O((n + 2*k) + (m + 2*k))

// Problem Link : https://leetcode.com/problems/build-a-matrix-with-conditions/description/?envType=daily-question&envId=2024-07-21

class Solution {
    private :
    void buildGraph(vector<int> adj[] , vector<vector<int>> &edges) {

        int n = edges.size();

        for(int i = 0 ; i < n ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
        }

        return ;
    }

    vector<int> khansAlgo(vector<int> adj[] , int k) {

        vector<int> indegree(k+1 , 0);

        for(int i = 1 ; i <= k ; i++) {

            for(int &neigh : adj[i]) {
                int u = i;
                int v = neigh;

                indegree[v]++;
            }
        }

        queue<int> q;

        for(int i = 1 ; i <= k ; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoSort;

        while(!q.empty()) {

            int node = q.front();

            q.pop();

            topoSort.push_back(node);


            for(int &neigh : adj[node]) {
                indegree[neigh]--;

                if(indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        int noOfNodes = topoSort.size();

        if(noOfNodes < k) {
            topoSort.resize(0);
        }

        return topoSort;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> adj1[k+1] , adj2[k+1];

        buildGraph(adj1 , rowConditions); 
        buildGraph(adj2 , colConditions);

        vector<int> rowOrder = khansAlgo(adj1 , k);
        vector<int> colOrder = khansAlgo(adj2 , k);

        vector<vector<int>> matrix(k , vector<int>(k , 0));

        if(rowOrder.size() == 0 or colOrder.size() == 0) {
            vector<vector<int>> result;
            return result;
        }

        int i = 0;
        map<int , int> mp;

        while(i < k) {
            matrix[i][0] = rowOrder[i];

            mp[rowOrder[i]] = i;
            i++;
        }

        i = 0;
        int j = 0;

        while(i < colOrder.size()) {
            int ele = colOrder[i];

            int row = mp[ele];

            swap(matrix[row][0] , matrix[row][j]);
            j++;
            i++;
        }

        return matrix;
    }
};
