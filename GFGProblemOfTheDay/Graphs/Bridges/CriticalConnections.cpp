// Time Complexity : O(V + E) + O(ElogE)
// Space Complexity : O(V + E) + O(V) 

// Problem Link : https://www.geeksforgeeks.org/problems/critical-connections/1

class Solution {
    private :
    int c;
    void dfs(vector<int> adj[],int node,int par,vector<vector<int>> &res,vector<int> &toi,vector<int> &low,vector<bool> &vis)
    {
        vis[node] = true;
        toi[node] = low[node] = ++c;
        
        for(auto neigh : adj[node])
        {
            if(neigh == par)
            continue;
            
            if(!vis[neigh])
            {
                dfs(adj,neigh,node,res,toi,low,vis);
                
                low[node] = min(low[node] , low[neigh]);
                
                if(low[neigh] > toi[node])
                {
                    // bridge edge
                    vector<int> v(2,0);
                    if(neigh < node)
                    {
                        v[0] = neigh;
                        v[1] = node;
                    }
                    else
                    {
                        v[0] = node;
                        v[1] = neigh;
                    }
                    res.push_back(v);
                }
            }
            else
            low[node] = min(low[node] , low[neigh]);
        }
        return ;
    }
    static bool compare(vector<int> &v1,vector<int> &v2)
    {
        if(v1[0] == v2[0])
        {
            return v1[1] < v2[1];
        }
        
        return v1[0] < v2[0];
    }
public:
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    vector<vector<int>> res;
	    vector<int> toi(V,0) , low(V,0);
	    c = 0;
	    vector<bool> vis(V,false);
	    dfs(adj,0,-1,res,toi,low,vis);
	    sort(res.begin(),res.end(),compare);
	    return res;
	}
};