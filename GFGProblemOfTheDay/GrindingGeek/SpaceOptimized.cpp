class Solution{
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n+1 , vector<int>(total+1 , 0));
        
        vector<int> ahead(total+1 , 0);
        
        for(int ind = n-1 ; ind >= 0 ; ind--) {
            
            vector<int> curr(total+1 , 0);
            for(int val = 0 ; val <= total ; val++) {
                
                int pick = 0 , unpick;
        
                if(cost[ind] <= val) {
                    int remainingTotal = val - cost[ind];
                    remainingTotal += (int)(0.9 * cost[ind]);
                    pick = 1 + ahead[remainingTotal];
                }
                
                unpick = ahead[val];
                
                curr[val] = max(pick , unpick);
            }
            
            ahead = curr;
        }
        
        return ahead[total];
    }
};