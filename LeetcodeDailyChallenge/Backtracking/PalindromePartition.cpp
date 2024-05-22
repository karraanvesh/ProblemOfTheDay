// Time  Complexity : O(n ^ 3)
// Space Complexity : O(n * n)

// Problem Link : https://leetcode.com/problems/palindrome-partitioning/?envType=daily-question&envId=2024-05-22

class Solution {
    private :
    bool isPalindrome(string &str) {
        int left , right;
        left = 0;
        right = str.length() - 1;

        while(left <= right) {

            if(str[left] != str[right])
            return false;

            left++;
            right--;
        }

        return true;
    }
    void f(string &str , int ind , int n , vector<vector<string>> &result , vector<string> &vect) {

        if(ind == n) {
            result.push_back(vect);
            return ;
        }

        string currStr;

        for(int i = ind ; i < n ; i++) {
            currStr += str[i];

            if(isPalindrome(currStr)) {
                vect.push_back(currStr);
                f(str , i + 1 , n , result , vect);
                vect.pop_back();
            }
        }

        return ;
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();

        vector<vector<string>> result;
        vector<string> vect;

        f(s , 0 , n , result , vect);

        return result;
    }
};