// Time Complexity : O(2 * n * m) ~ O(n * m)
// Space Complexity : O(n * m)

class Solution {
    private :
    bool isSafe(int i , int j , int n , int m) {
        return (i >= 0 and i < n and j >= 0 and j < m);
    }
    void bfs(int i , int j , vector<vector<char>> &grid , vector<vector<bool>> &visited , int n , int m) {
        queue<pair<int , int>> q;

        q.push({i , j});
        visited[i][j] = true;

        int dirRow[] = {-1 , 1 , 0 , 0};
        int dirCol[] = {0 , 0 , -1 , 1};

        while(!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;

            q.pop();

            for(int k = 0 ; k < 4 ; k++) {
                int newRow = currRow + dirRow[k];
                int newCol = currCol + dirCol[k];

                if(isSafe(newRow , newCol , n , m) and grid[newRow][newCol] == '1' and !visited[newRow][newCol]) {
                    q.push({newRow , newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }

        return ;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n , vector<bool>(m , false));
        int noOfIslands = 0;

        for(int i = 0 ; i < n ; i++) {

            for(int j = 0 ; j < m ; j++) {

                if(grid[i][j] == '1' and !visited[i][j]) {
                    noOfIslands++;

                    bfs(i , j , grid , visited , n , m);
                }
            } 
        }

        return noOfIslands;
    }
};