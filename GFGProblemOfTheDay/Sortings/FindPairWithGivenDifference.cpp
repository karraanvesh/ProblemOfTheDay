// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        sort(arr.begin() , arr.end());
        
        if(x == 0) {
            
            for(int i = 0 ; i < n - 1; i++) {
                
                if(arr[i] == arr[i+1])
                return 1;
            }
            
            return -1;
        }
        
        map<int , int> mp;
        
        for(int i = 0 ; i < n ; i++) {
            mp[arr[i]]++;
        }
        
        for(int i = 0 ; i < n ; i++) {
            int ele = x + arr[i];
            
            if(mp.count(ele) >= 1)
            return 1;
            
        }
        
        return -1;
    }
};