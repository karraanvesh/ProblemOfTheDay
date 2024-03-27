// Time  Complexity : O(n * m)
// Space Complexity : O(n * m)

// Problem Link : https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1

class Solution
{
    private :
    bool isSafe(int row , int col , int n , int m) {
        return (row >= 0 and row < n and col >= 0 and col < m);
    }
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       int rows = mat.size();
       int cols = mat[0].size();
       
       vector<vector<int>> grid;
       grid = mat;
       
       int dirRow[] = {-1 , 1 , 0 , 0};
       int dirCol[] = {0 , 0 , -1 , 1};
       
       for(int i = 0 ; i < rows ; i++) {
           
           for(int j = 0 ; j < cols ; j++) {
               
               if(mat[i][j] == 0) {
                   
                   for(int k = 0 ; k < 4 ; k++) {
                       int newRow = i + dirRow[k];
                       int newCol = j + dirCol[k];
                       
                       if(isSafe(newRow , newCol , rows , cols)) {
                           grid[newRow][newCol] = 0;
                       }
                   }
               }
           }
       }
       
       queue<pair<int , pair<int , int>>> q;
       vector<vector<int>> dist(rows , vector<int>(cols , INT_MAX));
       
       for(int i = 0 ; i < rows ; i++) {
           
           if(grid[i][0] == 1) {
               
               q.push({0 , {i , 0}});
               dist[i][0] = 0;
           }
       }
       
       while(!q.empty()) {
           int steps = q.front().first;
           int currRow = q.front().second.first;
           int currCol = q.front().second.second;
           
           q.pop();
           
           if(currCol == cols - 1) return 1 + steps;
           
           for(int k = 0 ; k < 4 ; k++) {
               int newRow = currRow + dirRow[k];
               int newCol = currCol + dirCol[k];
               
               if(isSafe(newRow , newCol , rows , cols) and grid[newRow][newCol] == 1) {
                   
                   if(1 + steps < dist[newRow][newCol]) {
                       q.push({1 + steps  , {newRow , newCol}});
                       dist[newRow][newCol] = 1 + steps;
                   }
               }
           }
       }
       
       return -1;
    }
};