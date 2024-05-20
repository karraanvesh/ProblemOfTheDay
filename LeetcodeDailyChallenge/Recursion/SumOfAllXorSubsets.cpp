// Time  Complexity : O(2 ^ n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2024-05-20

class Solution {
    private : 
    int result;

    void f(vector<int> &nums , int ind , int xorVal) {

        if(ind == -1) {
            result += xorVal;

            return ;
        }

        f(nums , ind - 1 , xorVal ^ nums[ind]);
        f(nums , ind - 1 , xorVal);

        return ;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        result = 0;

        int n = nums.size();
        f(nums , n - 1 , 0);

        return result;
    }
};