// Time Complexity : O(n * total)
// Space Complexity : O(n * total)

class Solution{
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n+1 , vector<int>(total+1 , 0));
        
        for(int ind = n-1 ; ind >= 0 ; ind--) {
            
            for(int val = 0 ; val <= total ; val++) {
                
                int pick = 0 , unpick;
        
                if(cost[ind] <= val) {
                    int remainingTotal = val - cost[ind];
                    remainingTotal += (int)(0.9 * cost[ind]);
                    pick = 1 + dp[ind+1][remainingTotal];
                }
                
                unpick = dp[ind+1][val];
                
                dp[ind][val] = max(pick , unpick);
            }
        }
        
        return dp[0][total];
    }
};