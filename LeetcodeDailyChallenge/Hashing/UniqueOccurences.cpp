// Time Complexity : O(nlogn)
// Space Complexity : O(n)
// where n is the size of the arr

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();

        map<int , int> mp;

        for(int i = 0 ; i < n ; i++) {
            mp[arr[i]]++;
        } 

        map<int , int> :: iterator itr;
        set<int> uniqueOccurence;

        for(itr = mp.begin() ; itr != mp.end() ; itr++) {
            int freq = itr->second;

            if(uniqueOccurence.count(freq) == 0) {
                uniqueOccurence.insert(freq);
            } else {
                return false;
            }
        }

        return true;
    }
};