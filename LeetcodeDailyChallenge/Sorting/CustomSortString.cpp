// Time  Complexity : O(m * logm)
// Space Complexity : O(m)

// Problem Link : https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11

class Solution {
    private :
    static bool comp(pair<char , int> &p1 , pair<char , int> &p2) {
        if(p1.second < p2.second)
        return true;

        return false;
    }
public:
    string customSortString(string order, string s) {

        vector<int> arr(26 , -1);
        int n = order.length();
        int m = s.length();

        for(int i = 0 ; i < n ; i++) {
            int currChar = order[i] - 'a';
            arr[currChar] = i;
        }

        vector<pair<char , int>> vect;

        for(int i = 0 ; i < m ; i++) {
            char ch = s[i];
            int ind = arr[ch - 'a'];

            vect.push_back({ch , ind});
        }

        sort(vect.begin() , vect.end() , comp);

        string result;

        for(int i = 0 ; i < m ; i++) {
            char ch = vect[i].first;
            result += ch;
        }

        return result;

    }
};