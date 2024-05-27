// Time  Complexity : O(n * n)
// Space Complexity : O(n * n)

// Problem Link : https://www.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1

class Solution {
    int f(vector<int> &arr , int ind , int n , int prevInd , vector<vector<int>> &dp) {
        
        if(ind == n) {
            return 0;
        }
        
        if(dp[ind][prevInd + 1] != -1) return dp[ind][prevInd + 1];
        
        int pick = 0 , unpick;
        
        if(prevInd == -1) {
            pick = 1 + f(arr , ind + 1, n , ind , dp);
            
            unpick = 0 + f(arr , ind + 1 , n ,  prevInd , dp);
            
            return dp[ind][prevInd + 1] = max(pick , unpick);
        } 
        
        int diff = abs(arr[ind] - arr[prevInd]);
        
        if(diff == 1) {
            pick = 1 + f(arr , ind + 1 , n , ind , dp);
        }
        
        unpick = 0 + f(arr , ind + 1 , n , prevInd , dp);
        
        return dp[ind][prevInd + 1] =  max(pick , unpick);
    }
  public:
    int longestSubseq(int n, vector<int> &a) {
        vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , -1));
        
        return f(a , 0 , n , -1 , dp);
    }
};