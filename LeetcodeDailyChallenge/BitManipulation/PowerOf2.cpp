// Time  Complexity : O(1)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/power-of-two/description/?envType=daily-question&envId=2024-02-19

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;

        int result = n & (n - 1);
        
        return (result == 0);
    }
};