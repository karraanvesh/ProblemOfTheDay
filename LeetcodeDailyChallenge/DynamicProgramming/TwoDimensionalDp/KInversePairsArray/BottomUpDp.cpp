// Time Complexity  : O(n * k)
// Space Complexity : O(n * k)

class Solution {
    private :
    int mod = 1e9 + 7;
public:
    int kInversePairs(int n, int k) {

        vector<vector<int>> dp(n , vector<int>(k+1 , 0));

        dp[n-1][0] = 1;
        int steps = k;

        for(int s = n-2 ; s >= 0 ; s--) {

            for(int steps = 0 ; steps <= k ; steps++) {

                int result = 0;
                for(int i = s ; i < n ; i++) {
                    int diff = i - s;

                    if(diff <= steps) {
                        int reversePairCount = dp[s+1][steps - diff];

                        result = (result%mod + reversePairCount%mod)%mod;  
                    }
                }

                dp[s][steps] = result;   
            }
        }

        return dp[0][steps];
    }
};