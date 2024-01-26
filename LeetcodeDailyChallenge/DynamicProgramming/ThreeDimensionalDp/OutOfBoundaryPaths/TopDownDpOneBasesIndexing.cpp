// Time Complexity : O(n * m * maxMoves)
// Space Complexity : O(n * m * maxMoves) + O(n + m) (for auxilary stack space)
// where n and m are the rows and columns

class Solution {
    private :
    long mod = 1e9 + 7;
    long f(int i , int j , int n , int m , int maxMoves , vector<vector<vector<long>>> &dp) {

        if(i == 0 or j == 0 or i == n+1 or j == m+1) return 1;

        if(maxMoves == 0) return 0;

        if(dp[i][j][maxMoves] != -1)
        return dp[i][j][maxMoves];

        int dirRow[] = {-1 , 1 , 0 , 0};
        int dirCol[] = {0 , 0 , -1 , 1};

        long result = 0;

        for(int k = 0 ; k < 4 ; k++) {

            int newRow = i + dirRow[k];
            int newCol = j + dirCol[k];

            long x = f(newRow , newCol , n , m , maxMoves - 1 , dp);
            result = (result%mod + x%mod)%mod;
        }

        return dp[i][j][maxMoves] = result;
    }
public:
    int findPaths(int m, int n, int maxMoves, int startRow, int startCol) {
        
        swap(n , m);
        vector<vector<vector<long>>> dp(n+2 , vector<vector<long>> (m+2 , vector<long>(maxMoves+1 , -1)));

        return f(startRow+1 , startCol+1, n , m , maxMoves , dp);
    }
};