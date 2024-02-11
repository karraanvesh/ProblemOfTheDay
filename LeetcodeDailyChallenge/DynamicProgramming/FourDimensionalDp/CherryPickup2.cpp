// Time Complexity  : O(n * m * n * m)
// Space Complexity : O(n * m * n * m)

// Problem Link : https://leetcode.com/problems/cherry-pickup-ii/description/?envType=daily-question&envId=2024-02-11

class Solution {
    private :
     
    bool isSafe(int i , int j , int n , int m) {
        return (i >= 0 and i < n and j >= 0 and j < m);
    }
    int f(int row1 , int col1 , int row2 , int col2 , vector<vector<int>> &grid , int n , int m , 
    vector<vector<vector<vector<int>>>> &dp) {

        if(row1 == n-1) {

            if(row1 == row2 and col1 == col2) return grid[row1][col1];

            return (grid[row1][col1] + grid[row2][col2]);
        }

        if(dp[row1][col1][row2][col2] != -1) return dp[row1][col1][row2][col2];

        int dirRow[] = {1 , 1 , 1};
        int dirCol[] = {-1 , 0 , 1};

        int maxi = 0;

        for(int k = 0 ; k < 3 ; k++) {
            int newRow1 = row1 + dirRow[k];
            int newCol1 = col1 + dirCol[k];

            if(!isSafe(newRow1 , newCol1 , n , m))
            continue;

            for(int l = 0 ; l < 3 ; l++) {

                int newRow2 = row2 + dirRow[l];
                int newCol2 = col2 + dirCol[l];

                if(!isSafe(newRow2 , newCol2 , n , m))
                continue;

                int x = f(newRow1 , newCol1 , newRow2 , newCol2 , grid , n , m , dp);

                maxi = max(maxi , x);
            }
        }

        int val = 0;

        if(row1 == row2 and col1 == col2) val = grid[row1][col1];

        else 
        val = grid[row1][col1] + grid[row2][col2];

        return dp[row1][col1][row2][col2] = val + maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<vector<int>>>> dp(n , vector<vector<vector<int>>>(m , vector<vector<int>> (n , vector<int>(m , -1))));

        return f(0 , 0 , 0 , m-1 , grid , n , m , dp);
    }
};