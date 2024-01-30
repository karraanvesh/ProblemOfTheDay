// Time Complexity : O(n1 * n2 * n3)
// Space Complexity : O(n1 * n2 * n3)

class Solution
{
    private :
    int dp[30][30][30];
    public:

    int LCSof3 (string s1, string s2, string s3, int n1, int n2, int n3)
    {
      
       memset(dp , 0 , sizeof dp);
       
       for(int i = 1 ; i <= n1 ; i++) {
           
           for(int j = 1 ; j <= n2 ; j++) {
               
               for(int k = 1 ; k <= n3 ; k++) {
                   
                   if(s1[i-1] == s2[j-1] and s2[j-1] == s3[k-1]) {
                        dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                    }
                    
                    else
                    dp[i][j][k] = max({dp[i-1][j][k] , dp[i][j-1][k] , dp[i][j][k-1]});
               }
           }
       }
       
       return dp[n1][n2][n3];
    }
};