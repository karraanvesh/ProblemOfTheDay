// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        vector<int> mp(n+1 , 0) , result;
        
        for(int i = 0 ; i < (n + 2) ; i++) {
            int ele = arr[i];
            
            mp[ele]++;
            
            if(mp[ele] == 2)
            result.push_back(ele);
        }
        
        return result;
    }
};