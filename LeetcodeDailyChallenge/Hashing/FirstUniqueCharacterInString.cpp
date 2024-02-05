// Time  Complexity : O(2 * n) ~ O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<int> mp(26 , 0);

        for(int i = 0 ; i < n ; i++) {
            int currChar = s[i] - 'a';
            mp[currChar]++;
        }

        int result = -1;
        for(int i = 0 ; i < n ; i++) {
            int currChar = s[i] - 'a';
            int freq = mp[currChar];

            if(freq == 1) {
                result = i;
                break;
            }
        }

        return result;
    }
};