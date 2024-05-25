// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/you-and-your-books/1

class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        
        int i = 0;
        long long maxi = 0;
        
        while(i < n) {
            int mini = arr[i];
            
            long long score = 0;
            while(i < n and arr[i] <= k) {
                
                score += arr[i];
                i++;
            }
            
            maxi = max(maxi , score);
            i++;
        }
        
        return maxi;
    }
};