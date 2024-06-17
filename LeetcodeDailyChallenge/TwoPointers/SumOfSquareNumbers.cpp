// Time Complexity : O(sqrt(c))
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/sum-of-square-numbers/description/?envType=daily-question&envId=2024-06-17

class Solution {
public:
    bool judgeSquareSum(int c) {
        long low = 0 , high = sqrt(c);
        
        while(low <= high) {

            long sum = (low * low) + (high * high);
            
            if(sum == c) return true;
            
            else if(sum < c)
                low++;
            
            else 
                high--;
        }
        
        return false;
    }
};