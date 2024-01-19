// Time Complexity : O(n!) + O(n! * log(n!))
// Space Complexity : O(n!)
// where n is the size of arr 

// Problem Link : https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1

class Solution {
    private :
    void permute(int ind , int n , vector<int> &arr , vector<vector<int>> &result) {
        
        if(ind == n-1) {
            result.push_back(arr);
            return ;
        }
        
        set<int> st;
        
        for(int i = ind ; i < n ; i++) {
            
            if(st.count(arr[i]) == 0) {
                st.insert(arr[i]);
                swap(arr[i] , arr[ind]);
                permute( ind + 1, n , arr , result);
                swap(arr[i] , arr[ind]);
            }
        }
        
        return ;
    }
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>> result;
        
        permute(0 , n , arr , result);
        
        sort(result.begin() , result.end());
        
        return result;
    }
};