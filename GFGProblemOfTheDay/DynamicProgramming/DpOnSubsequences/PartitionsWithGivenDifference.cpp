// Time  Complexity : O(n * sum)
// Space Complexity : O(n * sum)

// Problem Link : https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

class Solution {
    private :
    int mod = 1e9 + 7;
    int f(vector<int> &arr , int ind , int target , vector<vector<int>> &dp) {
        
        if(ind == 0) {
            
            if(target == arr[ind] and arr[ind] == 0)
            return 2;
            
            if(arr[ind] == target or target == 0)
            return 1;
            
            return 0;
        }
        
        if(dp[ind][target] != -1)
        return dp[ind][target];
        
        int pick = 0 , unpick;
        
        if(arr[ind] <= target)
        pick = f(arr , ind - 1 , target - arr[ind] , dp);
        
        unpick = f(arr , ind - 1 , target , dp);
        
        return dp[ind][target] = (pick%mod + unpick%mod)%mod;
    }
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = 0;
        
        for(int i = 0 ; i < n ; i++) {
            sum += arr[i];
        }
        
        int target = (sum + d);
        
        if(target%2 == 1)
        return 0;
        
        target = target / 2;
        
        vector<vector<int>> dp(n , vector<int>(target + 1 , -1));
        
        
        return f(arr , n - 1 , target , dp);
    }
};