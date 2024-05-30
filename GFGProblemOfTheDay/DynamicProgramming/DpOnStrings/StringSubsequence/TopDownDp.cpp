// Time  Complexity : O(n * m)
// Space Complexity : O(n * m) + O(n) (for auxilary stack space)

// Problem Link : https://www.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1

class Solution {
    private :
    int mod = 1e9 + 7;
    int f(string &s1 , string &s2 , int i , int j , vector<vector<int>> &dp) {
        
        if(j == 0) return 1;
        
        if(i == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i - 1] == s2[j - 1]) {
            return dp[i][j] = (f(s1 , s2 , i - 1 , j - 1 , dp)%mod + f(s1 , s2 , i - 1 , j , dp)%mod)%mod;
        }
        
        return dp[i][j] = f(s1 , s2 , i - 1 , j , dp)%mod;
    }
  public:
    int countWays(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , -1));
        
        return f(s1 , s2 , n , m , dp);
    }
};