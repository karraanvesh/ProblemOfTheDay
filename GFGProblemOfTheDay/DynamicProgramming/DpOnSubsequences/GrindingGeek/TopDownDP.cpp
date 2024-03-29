// Time Complexity : O(n * total)
// Space Complexity : O(n * total) + O(n) (auxilary stack space)

// Problem Link : https://www.geeksforgeeks.org/problems/grinding-geek/1

class Solution{
    private:
    int f(vector<int> &cost , int ind , int total , int n , vector<vector<int>> &dp) {
        
        if(ind == n) return 0;
        
        if(dp[ind][total] != -1) return dp[ind][total];
        
        int pick = 0 , unpick;
        
        if(cost[ind] <= total) {
            int remainingTotal = total - cost[ind];
            remainingTotal += (int)(0.9 * cost[ind]);
            pick = 1 + f(cost , ind+1 , remainingTotal , n , dp);
        }
        
        unpick = f(cost , ind+1 , total , n , dp);
        
        return dp[ind][total] = max(pick , unpick);
    }
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n , vector<int>(total+1 , -1));
        
        return f(cost , 0 , total , n , dp);
    }
};