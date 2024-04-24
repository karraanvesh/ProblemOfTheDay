// Time  Complexity : O(n * m)
// Space Complexity : O(n * m)

class Solution
{
    private :
    int mod = 1e9 + 7;
public:
    int ways(int x, int y)
    {
        int n = x + 1;
        int m = y + 1;
        
        vector<vector<int>> dp(n , vector<int>(m , 0));
        
        for(int col = 0 ; col < m ; col++) {
            dp[n - 1][col] = 1;
        }
        
        for(int row = 0 ; row < n ; row++) {
            dp[row][m - 1] = 1;
        }
        
        for(int i = n - 2 ; i >= 0 ; i--) {
            
            for(int j = m - 2 ; j >= 0 ; j--) {
                
                int a = dp[i][j + 1];
                int b = dp[i + 1][j];
                
                dp[i][j] = (a%mod + b%mod)%mod;
            }
        }
        
        return dp[0][0];
    }
};