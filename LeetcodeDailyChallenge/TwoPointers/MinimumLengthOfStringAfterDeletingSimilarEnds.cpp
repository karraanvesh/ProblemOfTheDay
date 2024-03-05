// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/?envType=daily-question&envId=2024-03-05

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int left , right;
        left = 0;
        right = n - 1;
        
        while(left < right) {
            int temp = left;
            bool flag1 , flag2;
            flag1 = flag2 = false;
            
            while(left < right and s[left] == s[right]) {
                left++;
                flag1 = true;
            }
            
            while(left < right and s[right] == s[temp]) {
                right--;
                flag2 = true;
            }

            if(left == right and flag1 and !flag2) {
                right--;
                break;
            }
            
            if(!flag1 and !flag2)
                break;
        }

        int minLength;

        if(left > right) {
            minLength = 0;
        }

        else
        minLength = (right - left) + 1;
        
        return minLength;
        
    }
};