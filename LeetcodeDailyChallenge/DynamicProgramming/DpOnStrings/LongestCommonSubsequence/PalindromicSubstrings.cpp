// Time  Complexity : O(n * n)
// Space Complexity : O(n * n)

// Problem Link : https://leetcode.com/problems/palindromic-substrings/description/?envType=daily-question&envId=2024-02-10

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();

        vector<vector<int>> dp(n , vector<int>(n , 0));

        for(int i = 0 ; i < n ; i++) {
            dp[i][i] = 1;
        }

        int i = 0 , j = 1;

        while(j < n) {

            if(s[i] == s[j])
            dp[i][j] = 1;

            i++;
            j++;
        }

        for(int temp = 2 ; temp < n ; temp++) {
            int i = 0 , j = temp;

            while(j < n) {

                if(s[i] == s[j] and dp[i+1][j-1])
                dp[i][j] = 1;

                i++;
                j++;
            }
        }

        int noOfPalindromes = 0;

        for(int i = 0 ; i < n ; i++) {

            for(int j = i ; j < n ; j++) {

                if(dp[i][j])
                noOfPalindromes++;
            }
        }

        return noOfPalindromes;
    }
};