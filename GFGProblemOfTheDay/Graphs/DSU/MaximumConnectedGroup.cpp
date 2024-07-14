// Time  Complexity : O(n * m * log*n) ~ O(n * m)
// Space Complexity : O(n * m)

// Problem Link : https://www.geeksforgeeks.org/problems/maximum-connected-group/1

class DSU {
    public :
    vector<int> parent , size;
    
    DSU(int n) {
        
        for(int i = 0 ; i <= n ; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    int findPar(int node) {
        return parent[node] = (parent[node] == node) ? node : findPar(parent[node]);
    }
    
    void Union(int a , int b) {
        int parA = findPar(a);
        int parB = findPar(b);
        
        if(parA == parB) return ;
        
        if(size[parA] < size [parB]) {
            size[parB] += size[parA];
            parent[parA] = parB;
        }
        
        else {
            size[parA] += size[parB];
            parent[parB] = parA;
        }
    }
};
class Solution {
    private :
    bool isSafe(int i , int j , int n , vector<vector<int>> &grid) {
        return (i >= 0 and i < n and j >= 0 and j < n and grid[i][j]);
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        
        DSU obj(n*n);
        
        int dirRow[] = {-1 , 1 , 0 , 0};
        int dirCol[] = {0 , 0 , -1 , 1};
        
        for(int i = 0 ; i < n ; i++) {
            
            for(int j = 0 ; j < n ; j++) {
                
                if(grid[i][j]) {
                    
                    for(int k = 0 ; k < 4 ; k++) {
                        
                        int newRow = i + dirRow[k];
                        int newCol = j + dirCol[k];
                        
                        if(isSafe(newRow , newCol , n , grid)) {
                            int a = i*n + j;
                            int b = newRow*n + newCol;
                            
                            obj.Union(a , b);
                        }
                    }
                }
            }
        }
        
        int result = 0;
        bool flag = false;
        
        for(int i = 0 ; i < n ; i++) {
            
            for(int j = 0 ; j < n ; j++) {
                
                if(grid[i][j] == 0) {
                    
                    flag = true;
                    
                    set<int> st;
                    
                    for(int k = 0 ; k < 4 ; k++) {
                        
                        int newRow = i + dirRow[k];
                        int newCol = j + dirCol[k];
                        
                        if(isSafe(newRow , newCol , n , grid)) {
                            st.insert(obj.findPar(newRow * n + newCol));
                        }
                    }
                    
                    int islandSize = 0;
                    
                    for(auto it : st) {
                        islandSize += obj.size[it];
                    }
                    
                    result = max(result , islandSize + 1);
                    
                }
            }
        }
        
        if(!flag)
        result = n*n;
        
        return result;
    }
};