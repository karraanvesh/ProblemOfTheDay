// Time  Complexity : O(n * n)
// Space Complexity : O(n)

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<long> dp(n+1 , 0);

        for(int ind = n-1 ; ind >= 0 ; ind--) {
            long ct , maxi , maxSum;
            ct = maxi = maxSum = 0;

            for(int i = ind ; i < n ; i++) {
                ct++;

                if(ct <= k) {
                    if(arr[i] > maxi)
                    maxi = arr[i];
                    long partitionSum = dp[i+1];
                    long len = (i - ind) + 1;
                    long currSum = (len * maxi) + partitionSum;
                    maxSum = max(maxSum , currSum);
                } else {
                    break;
                }
            }

            dp[ind] = maxSum;
        }

        return dp[0];
    }
};