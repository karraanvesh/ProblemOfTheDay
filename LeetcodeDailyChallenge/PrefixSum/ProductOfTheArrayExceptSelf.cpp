// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/product-of-array-except-self/description/?envType=daily-question&envId=2024-03-15

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixProd(n , 0) , suffixProd(n , 0);
        prefixProd[0] = nums[0];
        suffixProd[n - 1] = nums[n - 1];

        for(int i = 1 ; i < n ; i++) {
            prefixProd[i] = prefixProd[i - 1] * nums[i];
            suffixProd[n - i - 1] = suffixProd[n - i] * nums[n - i - 1];
        }

        vector<int> result(n , 0);
        result[0] = suffixProd[1];
        result[n - 1] = prefixProd[n - 2];

        for(int i = 1 ; i < n - 1 ; i++) {
            int currProd = prefixProd[i - 1] * suffixProd[i + 1];
            result[i] = currProd;
        }

        return result;
    }
};