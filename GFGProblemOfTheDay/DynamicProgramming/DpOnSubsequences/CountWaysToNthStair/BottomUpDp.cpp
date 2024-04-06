// Time  Complexity : O(2 * n) ~ O(n)
// Space Complexity : O(2 * n) ~ O(n)

class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        vector<vector<long long>> dp(2 , vector<long long>(n+1 , -1));
        vector<int> arr(2 , 0);
        arr[0] = 1;
        arr[1] = 2;
        
        dp[0][0] = 1;
        
        for(int j = 1 ; j <= n ; j++) {
            
            if(j%arr[0] == 0)
            dp[0][j] = 1;
        }
        
        for(int ind = 1 ; ind < 2 ; ind++) {
            dp[ind][0] = 1;
            
            for(int j = 1 ; j <= n ; j++) {
                
                int pick = 0 , unpick;
        
                if(arr[ind] <= j)
                pick = dp[ind][j - arr[ind]];
                
                unpick = dp[ind - 1][j];
                
                dp[ind][j] = pick + unpick;
            }
            
        }
        
        long long result = dp[1][n];
        
        return result;
    }
};