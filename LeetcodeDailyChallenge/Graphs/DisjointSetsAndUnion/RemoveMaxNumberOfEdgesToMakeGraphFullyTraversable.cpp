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

    bool isConnected(int n) {
        set<int> st;

        for(int i = 1 ; i <= n ; i++) {
            st.insert(findPar(i));
        }

        bool result = (st.size() == 1);

        return result;
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

        for(int i = 0 ; i < m ; i++) {

            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];

            if(type == 3) {
                
                bool b = false;
                if(obj1.findPar(u) != obj1.findPar(v)) {
                    b = true;
                    obj1.Union(u , v);
                }

                if(obj2.findPar(u) != obj2.findPar(v)) {
                    b = true;
                    obj2.Union(u , v);
                }

                if(!b) {
                    result++;
                }

            }

            else if(type == 2) {

                if(obj2.findPar(u) != obj2.findPar(v)) {

                    obj2.Union(u , v);
                }

                else {
                    result++;
                }
            }

            else if(type == 1) {

                if(obj1.findPar(u) != obj1.findPar(v)) {

                    obj1.Union(u , v);
                }

                else {
                    result++;
                }
            }
        }

        bool canTraverse = obj1.isConnected(n) and obj2.isConnected(n);
        if(!canTraverse) return -1;

        return result;
    }
};