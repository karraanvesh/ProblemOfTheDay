// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1

class Solution {
  public:
    void zigZag(int n, vector<int> &arr) {
         vector<int> brr;
         brr = arr;
         sort(brr.begin() , brr.end());
         
         int ind = n - 1;
         
         for(int i = 1 ; i < n ; i += 2) {
             arr[i] = brr[ind];
             ind--;
         }
         
         for(int i = 0 ; i < n ; i += 2) {
             arr[i] = brr[ind];
             ind--;
         }
         
         return ;
    }
};