// Time  Complexity : O(2 * n) ~ O(n)
// Space Complexity : O(2 * n) ~ O(n)

class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        vector<int> arr(2 , 0);
        arr[0] = 1;
        arr[1] = 2;
        
        vector<long long> prev(n + 1 , 0);
        
        prev[0] = 1;
        
        for(int j = 1 ; j <= n ; j++) {
            
            if(j%arr[0] == 0)
            prev[j] = 1;
        }
        
        for(int ind = 1 ; ind < 2 ; ind++) {
            vector<long long> curr(n + 1 , 0);
            curr[0] = 1;
            
            for(int j = 1 ; j <= n ; j++) {
                
                int pick = 0 , unpick;
        
                if(arr[ind] <= j)
                pick = curr[j - arr[ind]];
                
                unpick = prev[j];
                
                curr[j] = pick + unpick;
            }
            prev = curr;
        }
        
        long long result = prev[n];
        
        return result;
    }
};