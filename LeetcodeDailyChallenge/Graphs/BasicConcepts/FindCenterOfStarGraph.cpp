// Time Complexity : O(V + E)
// Space Complexity : O(V)

// Problem Link : https://leetcode.com/problems/find-center-of-star-graph/description/?envType=daily-question&envId=2024-06-27

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int noOfEdges = edges.size();
        
        int n = noOfEdges + 1;
        
        vector<int> indegree(n + 1 , 0);
        
        for(int i = 0 ; i < noOfEdges ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            indegree[v]++;
            indegree[u]++;
        }
        
        for(int i = 1 ; i <= n ; i++) {
            
            if(indegree[i] == n - 1)
                return i;
        }
        
        return -1;
    }
};