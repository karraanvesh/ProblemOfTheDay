// Time  Complexity : O(n * logn)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());
        long long sumOfSides = 0;

        long long result = -1;

        for(int i = 0 ; i < n ; i++) {

            if(i >= 2) {
                long long longestSide = nums[i];
                long long remainingSum = sumOfSides;

                if(longestSide < remainingSum) {
                    result = (sumOfSides + nums[i]);
                }
            }
            
            sumOfSides += nums[i];
        }

        return result;
    }
};