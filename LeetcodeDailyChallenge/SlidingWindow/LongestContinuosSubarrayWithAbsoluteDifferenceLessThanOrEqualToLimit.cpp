// Time  Complexity : O(2 * n) ~ O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/?envType=daily-question&envId=2024-06-23

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        int mini , maxi;
        mini = INT_MAX;
        maxi = INT_MIN;

        int left , right , len , maxLen;
        left = right = 0;
        len = maxLen = 0;
        int minInd , maxInd;


        while(right < n) {

            if(nums[right] < mini) {
                mini = nums[right];
                minInd = right;
            }

            if(nums[right] > maxi) {
                maxi = nums[right];
                maxInd = right;
            }

            long diff = maxi - mini;

            if(diff > limit) {
                maxLen = max(maxLen , len);
                
                long fairValue = diff - limit;
                long ele1 , ele2;

                ele1 = mini + fairValue;
                ele2 = maxi - fairValue;
                
                int closeInd = min(minInd , maxInd);

                while(left < right and left < closeInd) {
                    left++;
                }

                while(left < right and (nums[left] < ele1 or nums[left] > ele2)) {
                    left++;
                }

                len = 0;
                right = left;

                mini = maxi = nums[right];
            }

            else {
                right++;
                len++;
            }
        }

        maxLen = max(maxLen , len);

        return maxLen;
    }
};