// Time Complexity  : O(2 ^ n)
// Space Complexity : O(n * 26) + O(n) (for auxilary stack space)
// where n is the number of strings 

// Problem Link : https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23

class Solution {
    private:
    bool isValid(vector<int> &arr , vector<int> &brr) {

        for(int i = 0 ; i < 26 ; i++) {

            if(brr[i] > 1 or (arr[i] and brr[i])) {
                return false;
            }
        }

        return true;
    }
    int maxSubsequence(int ind , vector<int> allFreq , vector<vector<int>> &freq , int n , 
    vector<string> &arr) {

        if(ind == n) { 
            return 0;
        }

        int pick = 0 , unpick;

        if(isValid(allFreq , freq[ind])) {
            vector<int> newFreq(26,0);

            for(int i = 0 ; i < 26 ; i++) {
                newFreq[i] = allFreq[i] + freq[ind][i];
            }

            int len = arr[ind].size();

            pick = len + maxSubsequence(ind+1 , newFreq , freq , n , arr);
        }

        unpick = 0 + maxSubsequence(ind+1 , allFreq , freq , n , arr);

        return max(pick , unpick);
    }
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<vector<int>> freq(n , vector<int>(26 , 0));

        for(int i = 0 ; i < n ; i++) {
            string str = arr[i];
            int len = str.length();

            for(int j = 0 ; j < len ; j++) {
                int ch = str[j] - 'a';
                freq[i][ch]++;
            }
        }

        vector<int> allFreq(26 , 0);

        return maxSubsequence(0 , allFreq , freq , n , arr);
    }
};