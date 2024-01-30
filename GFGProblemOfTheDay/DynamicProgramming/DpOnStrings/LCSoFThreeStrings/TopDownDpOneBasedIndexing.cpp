// Time Complexity : O(n1 * n2 * n3)
// Space Complexity : O(n1 * n2 * n3)

class Solution
{
    private :
    int dp[30][30][30];
    int f(string &s1 , string &s2 , string &s3 , int i , int j , int k ) {
        if(i == 0 or j == 0 or k == 0)
        return 0;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        if(s1[i-1] == s2[j-1] and s2[j-1] == s3[k-1]) {
            return dp[i][j][k] = 1 + f(s1 , s2 , s3 , i-1 , j-1 , k-1);
        }
        
        return dp[i][j][k] = max({f(s1 , s2 , s3 , i-1 , j , k) , f(s1 , s2 , s3 , i , j-1 , k) , f(s1 , s2 , s3 , i , j , k-1)});
    }
    public:

    int LCSof3 (string s1, string s2, string s3, int n1, int n2, int n3)
    {
      
       memset(dp , -1 , sizeof dp);
       
       return f(s1 , s2 , s3 , n1 , n2 , n3);
    }
};