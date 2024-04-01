// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/length-of-last-word/?envType=daily-question&envId=2024-04-01

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();

        int ind = n - 1;

        while(ind  >= 0 and s[ind] == ' ') {
            ind--;
        }

        int result = 0;
        while(ind >= 0 and s[ind] != ' ') {
            result++;
            ind--;
        }

        return result;
    }
};