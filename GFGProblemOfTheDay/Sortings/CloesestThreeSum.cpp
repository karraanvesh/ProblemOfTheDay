// Time  Complexity : O(n ^ 2)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/three-sum-closest/1

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        int n = arr.size();
        
        int minDiff = INT_MAX , maxSum = INT_MIN;
        sort(arr.begin() , arr.end());
        
        for(int i = 0 ; i < n-2 ; i++) {
            
            int sum = target - arr[i];
            int left = i+1 , right = n-1;
            
            while(left < right) {
                
                int currSum = arr[left] + arr[right];
                int diff = abs(sum - currSum);
                
 
                
                if(diff == minDiff)
                maxSum = max(maxSum , currSum + arr[i]);
                
                if(diff < minDiff) {
                    minDiff = diff;
                    maxSum = currSum + arr[i];
                }
                
                sum = sum;
                
                if(currSum < sum)
                left++;
                
                else 
                right--;
            }
        }
        
        return maxSum;
    }
};