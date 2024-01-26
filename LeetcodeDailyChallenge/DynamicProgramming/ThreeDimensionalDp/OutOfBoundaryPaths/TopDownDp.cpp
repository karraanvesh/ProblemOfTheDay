// Time Complexity : O(n * m * maxMoves)
// Space Complexity : O(n * m * maxMoves) + O(n + m) (for auxilary stack space)
// where n and m are the rows and columns

// Problem Link : https://leetcode.com/problems/out-of-boundary-paths/description/?envType=daily-question&envId=2024-01-26

class Solution {
    private :
    long mod = 1e9 + 7;
    long f(int i , int j , int n , int m , int maxMoves , int prevRow , int prevCol , 
    vector<vector<vector<long>>> &dp) {

        if(i == -1 or j == -1 or i == n or j == m) return 1;

        if(maxMoves == 0) return 0;

        if(dp[i][j][maxMoves] != -1)
        return dp[i][j][maxMoves];

        int dirRow[] = {-1 , 1 , 0 , 0};
        int dirCol[] = {0 , 0 , -1 , 1};

        long result = 0;

        for(int k = 0 ; k < 4 ; k++) {

            int newRow = i + dirRow[k];
            int newCol = j + dirCol[k];

            long x = f(newRow , newCol , n , m , maxMoves - 1 , i , j , dp);
            result = (result%mod + x%mod)%mod;
        }

        return dp[i][j][maxMoves] = result;
    }
public:
    int findPaths(int m, int n, int maxMoves, int startRow, int startCol) {
        
        swap(n , m);
        vector<vector<vector<long>>> dp(n , vector<vector<long>> (m , vector<long>(maxMoves+1 , -1)));

        return f(startRow , startCol , n , m , maxMoves , -1 , -1 , dp);
    }
};