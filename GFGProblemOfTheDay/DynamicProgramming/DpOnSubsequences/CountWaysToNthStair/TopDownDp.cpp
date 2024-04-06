// Time  Complexity : O(2 * n) ~ O(n)
// Space Complexity : O(2 * n) ~ O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1

class Solution {
    private :
    long long f(int n , vector<vector<long long>> &dp , vector<int> &arr , int ind) {
        
        if(ind == 0) {
            
            if(n == 0) return 1;
            
            if(n%arr[ind] == 0) return 1;
            
            return 0;
        }
        
        if(dp[ind][n] != -1) return dp[ind][n];
        
        int pick = 0 , unpick;
        
        if(arr[ind] <= n)
        pick = f(n - arr[ind] , dp , arr , ind);
        
        unpick = f(n , dp , arr , ind - 1);
        
        return dp[ind][n] = pick + unpick;
    }
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
         vector<vector<long long>> dp(2 , vector<long long>(n+1 , -1));
        vector<int> arr(2 , 0);
        arr[0] = 1;
        arr[1] = 2;
        
        long long result = f(n , dp , arr , 1);
        
        return result;
    }
};