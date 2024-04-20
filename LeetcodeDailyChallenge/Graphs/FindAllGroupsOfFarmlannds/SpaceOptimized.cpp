// Time  Complexity : O(n * m)
// Space Complexity : O(n * m)

class Solution {
    private :
    bool isSafe(int i , int j , int n , int m) {
        return (i >= 0 and i < n and j >= 0 and j < m);
    }
    void dfs(int i , int j , vector<vector<int>> &land , vector<vector<bool>> &visited , int &num , 
    pair<int,int> &p , int n , int m) {

        int ind = i * m + j;
        
        if(ind > num) {
            num = ind;
            p.first = i;
            p.second = j;
        }
        visited[i][j] = true;

        int dirRow[] = {-1 , 1 , 0 , 0};
        int dirCol[] = {0 , 0 , -1 , 1};

        for(int k = 0 ; k < 4 ; k++) {

            int newRow = i + dirRow[k];
            int newCol = j + dirCol[k];

            if(isSafe(newRow , newCol , n , m) and land[newRow][newCol] and !visited[newRow][newCol]) {
                dfs(newRow , newCol , land , visited , num , p , n , m);
            }
        }

        return ;
    }
    void bfs(int i , int j , vector<vector<int>> &land , vector<vector<bool>> &visited , int &num , 
    pair<int,int> &p , int n , int m) {
        
        visited[i][j] = true;

        int dirRow[] = {-1 , 1 , 0 , 0};
        int dirCol[] = {0 , 0 , -1 , 1};

        queue<pair<int , int>> q;

        q.push({i , j});

        while(!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;

            q.pop();

            int ind = currRow * m + currCol;
            
            if(ind > num) {
                num = ind;
                p.first = currRow;
                p.second = currCol;
            }

            for(int k = 0 ; k < 4 ; k++) {

            int newRow = currRow + dirRow[k];
            int newCol = currCol + dirCol[k];

                if(isSafe(newRow , newCol , n , m) and land[newRow][newCol] and !visited[newRow][newCol]) {
                    q.push({newRow , newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }

        return ;
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;

        int n = land.size();
        int m = land[0].size();
        vector<vector<bool>> visited(n , vector<bool>(m ,false));

        for(int i = 0 ; i < n ; i++) {

            for(int j = 0 ; j < m ; j++) {

                if(land[i][j] and !visited[i][j]) {
                    // start i , j
                    int num = i*m + j;
                    pair<int , int> p;
                    p.first = i;
                    p.second = j;

                    bfs(i , j , land , visited , num , p , n , m);

                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    v.push_back(p.first);
                    v.push_back(p.second);

                    result.push_back(v);
                }
            }
        }

        return result;
    }
};