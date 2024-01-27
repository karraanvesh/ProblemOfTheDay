// Time Complexity  : O(n * k)
// Space Complexity : O(2 * k) ~ O(k)

class Solution {
    private :
    int mod = 1e9 + 7;
public:
    int kInversePairs(int n, int k) {

        vector<int> ahead(k+1 , 0);
        ahead[0] = 1;
        int steps = k;

        for(int s = n-2 ; s >= 0 ; s--) {
            vector<int> curr(k+1 , 0);
            for(int steps = 0 ; steps <= k ; steps++) {

                int result = 0;
                for(int i = s ; i < n ; i++) {
                    int diff = i - s;

                    if(diff <= steps) {
                        int reversePairCount = ahead[steps - diff];

                        result = (result%mod + reversePairCount%mod)%mod;  
                    }
                }

                curr[steps] = result;   
            }
            ahead = curr;
        }

        return ahead[steps];
    }
};