// Time Complexity : O(n * m)
// Space Complexity : O(n * m) + O(m) (for auxilary stack space)

class Solution
{
    private :
    int mod = 1e9 + 7;
    int f(string &s , string &t , int i , int j , vector<vector<int>> &dp) {
        
        if(j == 0) return 1;
        
        if(i == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        
        if(s[i-1] == t[j-1]) {
            return dp[i][j] = (f(s , t , i-1 , j-1 , dp)%mod + f(s , t , i-1, j, dp)%mod)%mod;
        }
        
        return dp[i][j] = f(s , t , i-1 , j , dp)%mod;
    }
    public:
    int subsequenceCount(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        
        return f(s , t , n , m , dp);
    }
};