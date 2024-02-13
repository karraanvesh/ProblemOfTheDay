// Time  Complexity : O(sum_of_length_of_words)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=daily-question&envId=2024-02-13

class Solution {
    private :
    bool isPalindrome(string &str) {
        int n = str.length();
        int i = 0 , j = n-1;

        while(i < j) {

            if(str[i] != str[j])
            return false;

            i++;
            j--;
        }

        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        int noOfWords = words.size();
        string result = "";

        for(int i = 0 ; i < noOfWords ; i++) {

            if(isPalindrome(words[i])) {
                result = words[i];
                break;
            }
        }

        return result;
    }
};