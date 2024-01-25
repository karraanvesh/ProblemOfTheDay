// Time Complexity : O(n * m)
// Space Complexity : O(2 * m) ~ O(m)
// where n and m are the lengths of given strings .

class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<int> prev(m+1 , 0);

        for(int i = 1 ; i <= n ; i++) {

            vector<int> curr(m+1 , 0);
            for(int j = 1 ; j <= m ; j++) {
                if(s[i-1] == t[j-1]) {
                    curr[j] = 1 + prev[j-1];
                }

                else {
                    curr[j] = max(prev[j] , curr[j-1]);
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};