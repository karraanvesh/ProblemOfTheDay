// Time  Complexity : O(2 * n) ~ O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/binary-subarrays-with-sum/?envType=daily-question&envId=2024-03-14

class Solution {
    private :
    long noOfSubarrays(vector<int> &nums , int n , int target) {
        long totalSubarrays , left , right , sum;
        totalSubarrays = left = right = sum = 0;

        while(right < n) {
            sum += nums[right];

            if(sum >= target) {
                int len = (n - right) , ct = 1;

                while(left <= right and nums[left] != 1) {
                    left++;
                    ct++;
                }

                sum--;
                left++;

                totalSubarrays += (ct * len);
            }

            right++;
        }

        return totalSubarrays;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        if(goal == 0) {
            long result , ct;
            result = ct = 0;

            for(int i = 0 ; i < n ; i++) {

                if(nums[i] == 0) {
                    ct++;
                }

                else {
                    result += (ct * (ct + 1)) / 2;
                    ct = 0;
                }
            }

            result += (ct * (ct + 1)) / 2;

            return result;
        }

        long eq1 = noOfSubarrays(nums , n , goal);
        long eq2 = noOfSubarrays(nums , n , goal + 1);

        long result = eq1 - eq2;

        return result;
    }
};
