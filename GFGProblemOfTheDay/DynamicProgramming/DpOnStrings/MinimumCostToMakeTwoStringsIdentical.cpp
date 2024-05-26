// Time  Complexity : O(n * m)
// Space Complexity : O(n * m)

// Problem Link : https://www.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1

class Solution {

  public:
    int findMinCost(string X, string Y, int costX, int costY) {
        int n = X.size();
	    int m = Y.size();
	    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	        {
	            if(X[i-1] == Y[j-1])
	            dp[i][j] = 1 + dp[i-1][j-1];
	            
	            else
	            dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
	        }
	    }
	    int lcs = dp[n][m];
	    int c1 , c2;
	    c1 = c2 = 0;
	    c1 = (n - lcs) * costX;
	    
	    c2 = (m - lcs) * costY;
	    
	    return c1 + c2;
    }
};