// Time Complexity : O(n * m)
// Space Complexity : O(n * m) + O(n + m) (for auxilary stack space)
// where n and m are the lengths of given strings .

// Problem Link : https://leetcode.com/problems/longest-common-subsequence/description/?envType=daily-question&envId=2024-01-25

class Solution {
    private:
    int lcs(string &s , string &t , int i , int j , vector<vector<int>> &dp) {
        if(i == -1) return 0;

        if(j == -1) return 0;

        if(dp[i][j] != -1)
        return dp[i][j];
        
        if(s[i] == t[j]) {
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

        vector<vector<int>> dp(n , vector<int>(m , -1));

        return lcs(s , t , n-1 , m-1 , dp);
    }
};