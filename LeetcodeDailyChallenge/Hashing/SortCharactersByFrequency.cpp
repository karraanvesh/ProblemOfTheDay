// Time Complexity  : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07

class Solution {
    private :
    static bool comp(pair<char , int> &p1 , pair<char , int> &p2) {
        return (p1.second > p2.second);
    }
public:
    string frequencySort(string s) {
        int n = s.length();
        vector<int> mp(256 , 0);

        for(int i = 0 ; i < n ; i++) {
            int currChar = s[i];
            mp[currChar]++;
        }

        vector<pair<char , int>> arr;

        for(int i = 0 ; i < 256 ; i++) {
            char ch = '\0' + i;
            int freq = mp[i];

            if(freq) {
                arr.push_back({ch , freq});
            }
        }

        sort(arr.begin() , arr.end() , comp);
        int noOfChars = arr.size();
        string result;

        for(int i = 0 ; i < noOfChars ; i++) {
            char ch = arr[i].first;
            int freq = arr[i].second;

            while(freq > 0) {
                result += ch;
                freq--;
            }
        }

        return result;
    }
};