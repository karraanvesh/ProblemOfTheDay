// Time  Complexity : O(n * logn)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/?envType=daily-question&envId=2024-05-27

class Solution {
    private :
    int upperBound(vector<int> &nums , int target) {
        int n = nums.size();
        int low = 0 , high = n - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(nums[mid] >= target)
            high = mid - 1;

            else
            low = mid + 1;
        }

        return n - low;
    }
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        for(int i = 0 ; i < n ; i++) {
            int ub = upperBound(nums , i + 1);

            if(ub == i + 1)
            return ub;
        }

        return -1;
    }
};