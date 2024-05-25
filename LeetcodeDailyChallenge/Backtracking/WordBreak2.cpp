// Time  Complexity : O(exponential)
// Space Complexity : O(number_of_combinations)

// Problem Link : https://leetcode.com/problems/word-break-ii/description/?envType=daily-question&envId=2024-05-25

class Solution {
    private :
    void f(string s , string &str , int ind , int n , set<string> &st , vector<string> &result) {

        if(ind == n) {
            str.pop_back();
            result.push_back(str);

            str += ' ';

            return ;
        }

        string currStr;

        for(int i = ind ; i < n ; i++) {
            currStr += s[i];
            str += s[i];

            if(st.count(currStr)) {
                str += ' ';
                f(s , str , i + 1 , n , st , result);
                str.pop_back();
            }
        }

        while(str.length() > 0 and str[str.length() - 1] != ' ') {
            str.pop_back();
        }

        return ;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        int n = s.length();

        int noOfWords = wordDict.size();

        for(int i = 0 ; i < noOfWords ; i++) {
            st.insert(wordDict[i]);
        }

        vector<string> result;
        string str;

        f(s , str , 0 , n , st , result);

        return result;
    }
};