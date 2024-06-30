// Time  Complexity : O(logn + ElogE)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/?envType=daily-question&envId=2024-06-30

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
            size[parB] += size[parA];
            parent[parA] = parB;
        }

        else {
            size[parA] += size[parB];
            parent[parB] = parA;
        }

        return ;
    }
};

class Solution {
    private :
    static bool comp(vector<int> &v1 , vector<int> &v2) {

        return v1[0] > v2[0];
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU obj1(n) , obj2(n);

        int m = edges.size();
        int result = 0;
        sort(edges.begin() , edges.end() , comp);

        int ct1 = 0 , ct2 = 0;

        for(int i = 0 ; i < m ; i++) {

            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];

            if(type == 3) {

                if(obj1.findPar(u) != obj1.findPar(v)) {
                    ct1++;
                    obj1.Union(u , v);
                }

                if(obj2.findPar(u) != obj2.findPar(v)) {
                    ct2++;
                    obj2.Union(u , v);
                }

                else {
                    result++;
                }
            }

            else if(type == 2) {

                if(obj2.findPar(u) != obj2.findPar(v)) {
                    ct2++;
                    obj2.Union(u , v);
                }

                else {
                    result++;
                }
            }

            else if(type == 1) {

                if(obj1.findPar(u) != obj1.findPar(v)) {
                    ct1++;
                    obj1.Union(u , v);
                }

                else {
                    result++;
                }
            }
        }

        if(ct1 < n-1 or ct2 < n-1) 
        return -1;

        return result;
    }
};