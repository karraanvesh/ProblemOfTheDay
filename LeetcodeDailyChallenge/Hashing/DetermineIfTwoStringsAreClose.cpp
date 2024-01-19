// Time Complexity : O(n + m)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/determine-if-two-strings-are-close/?envType=daily-question&envId=2024-01-14

class Solution {
    private:
    void mapFreq(string &str , int n , vector<int> &mp) {

        for(int i = 0 ; i < n ; i++) {
            int ch = str[i] - 'a';
            mp[ch]++;
        }

        return ;
    }
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        if(n != m) return false;

        vector<int> mp1(26 , 0) , mp2(26 , 0);

        mapFreq(word1 , n , mp1);
        mapFreq(word2 , m , mp2);

        vector<int> mapFreq1 , mapFreq2;

        for(int i = 0 ; i < 26 ; i++) {

            if(mp1[i] and !mp2[i]) return false;

            if(!mp1[i] and mp2[i]) return false;

            if(mp1[i])
            mapFreq1.push_back(mp1[i]);

            if(mp2[i])
            mapFreq2.push_back(mp2[i]);
        }

        sort(mapFreq1.begin() , mapFreq1.end());
        sort(mapFreq2.begin() , mapFreq2.end());

        return (mapFreq1 == mapFreq2);
    }
};