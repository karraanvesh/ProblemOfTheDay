// Time  Complexity : O(2 * n) ~ O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/maximum-odd-binary-number/?envType=daily-question&envId=2024-03-01

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int noOfOnes = 0;

        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '1')
            noOfOnes++;
        }

        string result;

        if(noOfOnes == 0)
        return s;

        noOfOnes--;

        for(int i = 0 ; i < n-1 ; i++) {
            if(noOfOnes) {
            result += '1';
            noOfOnes--;
            }

            else
            result += '0';
        }

        result += '1';

        return result;
    }
};