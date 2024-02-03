// Time  Complexity : O(n * n)
// Space Complexity : O(n) + O(n) (for auxilary stack space)

// Proble Link : https://leetcode.com/problems/partition-array-for-maximum-sum/description/?envType=daily-question&envId=2024-02-03

class Solution {
    private:
    long f(vector<int> &arr , int ind , int n , int k , vector<long> &dp) {

        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        long ct , maxi , maxSum;
        ct = maxi = maxSum = 0;

        for(int i = ind ; i < n ; i++) {
            ct++;

            if(ct <= k) {
                if(arr[i] > maxi)
                maxi = arr[i];
                long partitionSum = f(arr , i+1 , n , k , dp);
                long len = (i - ind) + 1;
                long currSum = (len * maxi) + partitionSum;
                maxSum = max(maxSum , currSum);
            } else {
                break;
            }
        }

        return dp[ind] = maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<long> dp(n , -1);

        return f(arr , 0 , n , k , dp);
    }
};