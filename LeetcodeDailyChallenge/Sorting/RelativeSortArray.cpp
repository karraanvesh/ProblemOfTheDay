// Time Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/relative-sort-array/description/?envType=daily-question&envId=2024-06-11

class Solution {
    private :
    static bool comp(pair<int , int> &p1 , pair<int , int> &p2) {
        if(p1.second == 100000 and p2.second == 100000) {
            return p1.first < p2.first;
        }
        
        return p1.second < p2.second;
    }
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        
        map<int , int> mp;
        
        for(int i = 0 ; i < m ; i++)    {
            mp.insert({arr2[i] , i+1});
        }
        
        vector<pair<int , int>> vect;
        
        for(int i = 0 ; i < n ; i++)    {
            long ind = 100000;
            
            if(mp.find(arr1[i]) != mp.end()) {
                ind = mp[arr1[i]];
                vect.push_back({arr1[i] , ind});
             }
            else {
                vect.push_back({arr1[i] , ind});
            }
        }
        
        sort(vect.begin() , vect.end() , comp);
        
        for(int i = 0 ; i < n ; i++)    {
            arr1[i] = vect[i].first;
        }
        
        return arr1;
    }
};