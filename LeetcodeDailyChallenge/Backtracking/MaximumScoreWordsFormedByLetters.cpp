// Time  Complexity : O(2 ^ m)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/maximum-score-words-formed-by-letters/?envType=daily-question&envId=2024-05-24

class Solution {
    private :
    bool canWePick(vector<int> &brr , vector<int> &arr) {

        for(int i = 0 ; i < 26 ; i++) {

            if(brr[i]) {

                if(brr[i] > arr[i])
                return false;
            }
        }

        return true;
    }
    int f(vector<string> &words , int ind , int m , vector<int> &arr , vector<int> &score) {

        if(ind == m) {
            return 0;
        }

        int pick = 0 , unpick;

        string str = words[ind];

        int n = str.length();
        vector<int> brr(26 , 0);

        for(int i = 0 ; i < n ; i++) {
            int ch = str[i] - 'a';
            brr[ch]++;
        }

        if(canWePick(brr , arr)) {
            vector<int> temp = arr;
            int profit = 0;

            for(int i = 0 ; i < 26 ; i++) {

                if(brr[i]) {
                    profit += (brr[i] * score[i]);
                }

                temp[i] = temp[i] - brr[i];
            }

            pick = profit + f(words , ind + 1 , m , temp , score);
        }

        unpick = 0 + f(words , ind + 1 , m , arr , score);

        return max(pick , unpick);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = letters.size();
        vector<int> arr(26 , 0);

        for(int i = 0 ; i < n ; i++) {
            int ch = letters[i] - 'a';
            arr[ch]++;
        }

        int m = words.size();

        return f(words , 0 , m , arr , score);
    }
};