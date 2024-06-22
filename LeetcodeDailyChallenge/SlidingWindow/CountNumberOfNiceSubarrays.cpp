// Time  Complexity : O(4 * n) ~ O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/count-number-of-nice-subarrays/?envType=daily-question&envId=2024-06-22

class Solution {
    long noOfSubarrays(vector<int> &arr , int n , int target) {
        long totalSubarrays = 0;

        long left , right , sum;
        left = right = sum = 0;

        while(right < n) {

            sum += arr[right];

            if(sum == target) {
                int len = n - right , ct = 1;

                while(left <= right and arr[left] == 0) {
                    ct++;
                    left++;
                }

                totalSubarrays += (len * ct);
                sum--;
                left++;
            }

            right++;
        }

        return totalSubarrays;
    }
public:
    long numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(n , 0);

        for(int i = 0 ; i < n ; i++) {

            if(nums[i]%2)
            arr[i] = 1;
        }

        long eq1 = noOfSubarrays(arr , n , k);
        long eq2 = noOfSubarrays(arr , n , k + 1);

        long result = eq1 - eq2;

        return result;
    }
};