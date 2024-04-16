// Time  Complexity : O(2 * n) ~ O(n)
// Space Complexity : O(4 * n) ~ O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/minimize-the-difference/1

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        vector<int> preMin(n , 0) , preMax(n , 0) , postMin(n , 0) , postMax(n , 0);
        preMin[0] = preMax[0] = arr[0];
        postMax[n - 1] = postMin[n - 1] = arr[n - 1];
        
        for(int i = 1 ; i < n ; i++) {
            preMin[i] = min(arr[i] , preMin[i-1]);
            preMax[i] = max(arr[i] , preMax[i-1]);
            
            postMin[n - i - 1] = min(arr[n - i - 1] , postMin[n - i]);
            postMax[n - i - 1] = max(arr[n - i - 1] , postMax[n - i]);
        }
        
        int i , j;
        i = 0;
        j = k - 1;
        int result = INT_MAX;
        
        while(j < n) {
            int diff;
            if(i == 0) {
                diff = postMax[j + 1] - postMin[j + 1];
            }
            
            else if(j == n - 1) {
                diff = preMax[i - 1] - preMin[i - 1];
            }
            
            else {
                int mini = min(preMin[i - 1] , postMin[j + 1]);
                int maxi = max(preMax[i - 1] , postMax[j + 1]);
                
                diff = maxi - mini;
            }
            
            result = min(result , diff);
            
            i++;
            j++;
        }
        
        return result;
    }
};