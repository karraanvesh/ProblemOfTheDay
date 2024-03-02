// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n , 0);
        int ind = n - 1;

        int left = 0 , right = n - 1;

        while(left <= right) {
            int val1 = nums[left] * nums[left];
            int val2 = nums[right] * nums[right];

            if(val1 > val2) {
                result[ind] = val1;
                left++;
            }

            else {
                result[ind] = val2;
                right--;
            }

            ind--;
        }

        return result;
    }
};