// Time  Complexity : O(log* n + m)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/find-if-path-exists-in-graph/description/?envType=daily-question&envId=2024-04-21

class DSU {
    private :
    vector<int> parent , size;

    public :
    DSU(int n) {
        for(int i = 0 ; i <= n ; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findPar(int node) {
        if(parent[node] == node) return node;

        return parent[node] = findPar(parent[node]);
    }

    void Union(int a , int b) {
        int parA = findPar(a);
        int parB = findPar(b);

        if(parA == parB) return ;

        if(size[parA] < size[parB]) {
            parent[parA] = parB;
            size[parB] += size[parA];
        }

        else {
            parent[parB] = parA;
            size[parA] += size[parB];
        }

        return ;
    }
};


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];

        DSU obj(n);
        int m = edges.size();

        for(int i = 0 ; i < m ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            obj.Union(u , v);
        }

        int sourcePar = obj.findPar(source);
        int destPar = obj.findPar(destination);

        if(sourcePar == destPar)
        return true;

        return false;
    }
};