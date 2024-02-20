// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        long totalSum = (n * (n + 1)) / 2;
        long sum = 0;

        for(int i = 0 ; i < n ; i++) {
            sum += nums[i];
        }

        int result = totalSum - sum;

        return result;
    }
};