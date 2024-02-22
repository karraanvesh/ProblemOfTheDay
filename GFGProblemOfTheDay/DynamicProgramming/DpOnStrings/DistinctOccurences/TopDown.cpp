// Time Complexity : O(n * m)
// Space Complexity : O(n * m) + O(m) (for auxilary stack space)

// Problem Link : https://www.geeksforgeeks.org/problems/distinct-occurrences/1

class Solution
{
    private :
    int mod = 1e9 + 7;
    int f(string &s , string &t , int i , int j , vector<vector<int>> &dp) {
        
        if(j == -1) return 1;
        
        if(i == -1) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        
        if(s[i] == t[j]) {
            return dp[i][j] = (f(s , t , i-1 , j-1 , dp)%mod + f(s , t , i-1, j, dp)%mod)%mod;
        }
        
        return dp[i][j] = f(s , t , i-1 , j , dp)%mod;
    }
    public:
    int subsequenceCount(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n+1 , vector<int>(m , -1));
        
        return f(s , t , n-1 , m-1 , dp);
    }
};