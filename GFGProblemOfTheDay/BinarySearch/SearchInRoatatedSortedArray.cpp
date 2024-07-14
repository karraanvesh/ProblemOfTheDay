// Time  Complexity : O(logn)
// Space Complexity: O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int low = 0 , high= n-1;
        
        while(low < high) {
            int mid = low + (high - low)/2;
            
            if(arr[low] <= arr[mid]) {
                
                if(key >= arr[low] and key <= arr[mid])
                high = mid;
                
                else 
                low = mid + 1;
            }
            
            else {
                
                if(key >= arr[mid] and key <= arr[high])
                low = mid;
                
                else 
                high = mid - 1;
            }
        }
        
        if(arr[low] != key) return -1;
        
        return low;
    }
};