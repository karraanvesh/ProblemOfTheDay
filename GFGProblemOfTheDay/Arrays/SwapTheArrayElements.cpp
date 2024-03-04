// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/need-some-change/1

class Solution{
  public:
    void swapElements(int arr[], int n){
        
        for(int i = 0 ; i < n - 2 ; i++) {
            swap(arr[i] , arr[i+2]);
        }
    }
};