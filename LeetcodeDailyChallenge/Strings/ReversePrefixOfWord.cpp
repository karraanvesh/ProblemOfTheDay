// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/reverse-prefix-of-word/?envType=daily-question&envId=2024-05-01

class Solution {
public:
    string reversePrefix(string word, char ch) {
        vector<int> mp(26 , -1);

        int n = word.length();

        for(int i = 0 ; i < n ; i++) {
            int currCh = word[i] - 'a';

            if(mp[currCh] == -1)
            mp[currCh] = i;
        }

        int targetCh = ch - 'a';

        if(mp[targetCh] == -1) return word;

        int i = 0 , j = mp[targetCh];

        while(i <= j) {
            swap(word[i] , word[j]);
            i++;
            j--;
        }

        return word;
    }
};