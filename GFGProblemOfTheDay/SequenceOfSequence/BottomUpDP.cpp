// Time Complexity : O(n * m)
// Space Complexity : O(n * m)

class Solution{
public:
    int numberSequence(int m, int n){
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
        
        for(int i = 0 ; i <= m ; i++) {
            dp[0][i] = 1;
        }
        
        for(int temp = 1 ; temp <= n ; temp++) {
            
            for(int prev = 0 ; prev <= m ; prev++) {
                int seqCount = 0;
        
                int start = (prev == 0) ? 1 : 2*prev;
                
                for(int i = start ; i <= m ; i++) {
                    
                    int x = dp[temp-1][i];
                    seqCount += x;
                }
            
                dp[temp][prev] = seqCount;
            }
        }
        
        return dp[n][0];
    }
};