// Time Complexity : O(n * m)
// Space Complexity : O(n * m) + O(n + m) (for auxilary stack space)
// where n and m are the lengths of given strings .

class Solution {
    private:
    int lcs(string &s , string &t , int i , int j , vector<vector<int>> &dp) {
        if(i == 0) return 0;

        if(j == 0) return 0;

        if(dp[i][j] != -1)
        return dp[i][j];
        
        if(s[i-1] == t[j-1]) {
            return dp[i][j] = 1 + lcs(s , t , i-1 , j-1 , dp);
        }

        int a = lcs(s , t , i-1 , j , dp);
        int b = lcs(s , t , i , j-1 , dp);

        return dp[i][j] = max(a , b);
    }
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));

        return lcs(s , t , n , m , dp);
    }
};