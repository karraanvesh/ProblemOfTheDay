// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16

class Solution {
    private :
    static bool comp(pair<long , long> &p1 , pair<long , long> &p2) {
        return p1.second < p2.second;
    }
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        map<long , long> mp;

        for(int i = 0 ; i < n ; i++) {
            mp[arr[i]]++;
        }

        vector<pair<long,long>> Elefreq;
        map<long , long> :: iterator itr;

        for(itr = mp.begin() ; itr  != mp.end() ; itr++) {
            long ele = itr->first;
            long freq = itr->second;

            Elefreq.push_back({ele , freq});
        }

        sort(Elefreq.begin() , Elefreq.end() , comp);
        int m = Elefreq.size();
        int uniqueNumbers = m;

        int i = 0;

        while(i < m) {

            if(Elefreq[i].second <= k) {
                k -= Elefreq[i].second;
                uniqueNumbers--;
            }
            
            else {
                break;
            }

            i++;
        }

        return uniqueNumbers;
    }
};