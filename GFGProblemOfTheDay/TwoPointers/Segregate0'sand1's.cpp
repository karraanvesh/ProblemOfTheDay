// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        
        int n = arr.size();
        int left , right;
        left = right = 0;
        
        while(left < n and right < n) {
            
            if(!arr[left] and !arr[right]) {
                left++;
                right++;
            }
            
            else if(!arr[left] and arr[right]) {
                left++;
            }
            
            else if(arr[left] and !arr[right]) {
                swap(arr[left] , arr[right]);
                left++;
            }
            
            else {
                right++;
            }
        }
        
        return ;
    }
};