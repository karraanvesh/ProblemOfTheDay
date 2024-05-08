// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/relative-ranks/description/?envType=daily-question&envId=2024-05-08

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp;

        temp = score;
        sort(temp.begin() , temp.end() , greater<int>());

        map<int , int> mp;
        int n = score.size();

        for(int i = 0 ; i < n ; i++) {
            mp[temp[i]] = i;
        }

        vector<string> result;

        for(int i = 0 ; i < n ; i++) {
            int ind = mp[score[i]];

            if(ind == 0) {
                result.push_back("Gold Medal");
            }

            else if(ind == 1) {
                result.push_back("Silver Medal");
            }

            else if(ind == 2) {
                result.push_back("Bronze Medal");
            }

            else {
                int num = ind + 1;

                vector<int> v;

                while(num > 0) {
                    v.push_back(num%10);
                    num /= 10;
                }

                reverse(v.begin() , v.end());

                string str;

                for(int i = 0 ; i < v.size() ; i++) {
                    str += ('0' + v[i]);
                }

                result.push_back(str);
            }
        }

        return result;
    }
};