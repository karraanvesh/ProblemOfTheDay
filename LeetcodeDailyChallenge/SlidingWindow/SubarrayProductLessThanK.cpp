// Time  Complexity : O(2 * n) ~ O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/subarray-product-less-than-k/?envType=daily-question&envId=2024-03-27

class Solution {
    private :
    long noOfSubarrays(vector<int> &nums , int n , int k) {
        long left , right , result , prod = 1;
        left = right = result = 0;

        while(right < n) {
            prod = prod * nums[right];

            if(prod >= k) {
                int len = n - right , ct = 1;
                long prevEle = nums[left];

                while(left <= right and (prod / prevEle) >= k) {
                    prod = prod / prevEle;
                    left++;
                    ct++;
                    prevEle = nums[left];
                }

                prod /= nums[left];
                left++;

                result += (len * ct);
            }

            right++;
        }

        return result;
    }
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        int n = nums.size();
        long totalSubarrays = (n * (n + 1)) / 2;

        long ans = noOfSubarrays(nums , n , k);

        long result = totalSubarrays - ans;

        return result;
    }
};