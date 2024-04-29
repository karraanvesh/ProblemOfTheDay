// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/?envType=daily-question&envId=2024-04-29

class Solution {
    private :
    int countBits(int num) {
        int ct = 0;

        while(num > 0) {

            if(num & 1)
            ct++;

            num /= 2;
        }

        return ct;
    }
public:
    int minOperations(vector<int>& nums, int k) {
        int xorVal = 0;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++) {
            xorVal = xorVal ^ nums[i];
        }

        int num = k ^ xorVal;

        int result = countBits(num);

        return result;
    }
};