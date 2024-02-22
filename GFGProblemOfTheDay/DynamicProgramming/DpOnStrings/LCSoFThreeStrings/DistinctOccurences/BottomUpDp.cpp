// Time Complexity : O(n * m)
// Space Complexity : O(n * m)

class Solution
{
    private :
    int mod = 1e9 + 7;
    public:
    int subsequenceCount(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
        
        for(int i = 0 ; i <= n ; i++) {
            dp[i][0] = 1;
        }
        
        for(int i = 1 ; i <= n ; i++) {
            
            for(int j = 1 ; j <= m ; j++) {
                
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = (dp[i-1][j-1]%mod + dp[i-1][j]%mod)%mod;
                }
                
                else
                dp[i][j] = dp[i-1][j]%mod;
            }
        }
        
        return dp[n][m];
    }
};