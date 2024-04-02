// Time  Complexity : O(n)
// Space Complexity : O(256) ~ O(1)

// Problem Link : https://leetcode.com/problems/isomorphic-strings/?envType=daily-question&envId=2024-04-02

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<int> mp(256 , 0);
        set<int> st;

        for(int i = 0 ; i < n ; i++) {
            int ch1 = s[i];
            int ch2 = t[i];

            if(mp[ch1] == 0) {

                if(st.count(ch2) == 0) {
                    mp[ch1] = ch2;
                    st.insert(ch2);
                }

                else
                return false;
            }

            else {

                if(mp[ch1] != ch2)
                return false;
            }
        }

        return true;
    }
};