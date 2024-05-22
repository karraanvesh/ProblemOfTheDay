// Time  Complexity : O(n * n)
// Space Complexity : O(n * n)

// Problem Link : https://www.geeksforgeeks.org/problems/find-if-string-is-k-palindrome-or-not1923/1

class Solution{
public:
    int kPalindrome(string str1, int n, int k)
    {
        string str2 = str1;
        reverse(str2.begin() , str2.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
                
                else
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        int lcs = n - dp[n][n];
        if(lcs <= k)
        return 1;
        return 0;
    }
};