// Time Complexity : O(n * logn)
// Space Complexity : O(2*n + logn) ~ O(n + logn)

// Problem Link : https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1

class Solution {
    private :
    static bool comp(pair<char , int> &p1 , pair<char , int> &p2) {
        
        return (p1.second < p2.second);
    }
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        map<char , int> mp;
        
        // { !,#,$,%,&,*,?,@,^ }
        
        mp.insert({'!' , 1});
        mp.insert({'#' , 2});
        mp.insert({'$' , 3});
        mp.insert({'%' , 4});
        mp.insert({'&' , 5});
        mp.insert({'*' , 6});
        mp.insert({'?' , 7});
        mp.insert({'@' , 8});
        mp.insert({'^' , 9});
        
        vector<pair<char , int>> arr , brr;
        
        for(int i = 0 ; i < n ; i++) {
            int val = mp[nuts[i]];
            arr.push_back({nuts[i] , val});
            val = mp[bolts[i]];
            brr.push_back({bolts[i] , val});
        }
        
        sort(arr.begin() , arr.end() , comp);
        sort(brr.begin() , brr.end() , comp);
        
        for(int i = 0 ; i < n ; i++) {
            nuts[i] = arr[i].first;
            bolts[i] = brr[i].first;
        }
        
        return ;
    }
};