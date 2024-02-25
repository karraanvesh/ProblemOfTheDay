// Time Complexity : O(3 * n) ~ O(n)
// Space Complexity : O(3 * n) ~ O(n) + O(n / 3) ~ O(n) (for auxilary stack space)

// Problem Link : https://www.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1

class Solution
{
    private :
    long long f(int ind , vector<int> &arr , long long n , vector<vector<long long>> &dp) {
        
        if(ind == 0) {
            
            if(n%arr[ind] == 0)
            return 1;
            
            return 0;
        }
        
        if(dp[ind][n] != -1) return dp[ind][n];
        
        long long pick = 0 , unpick;
        
        if(arr[ind] <= n)
        pick = f(ind , arr , n - arr[ind] , dp);
        
        unpick = f(ind - 1 , arr , n , dp);
        
        return dp[ind][n] = pick + unpick;
    }
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	vector<int> arr;
    	arr.push_back(3);
    	arr.push_back(5);
    	arr.push_back(10);
    	
    	vector<vector<long long>> dp(3 , vector<long long>(n+1 , -1));
    	
    	return f(2 , arr , n , dp);
    }
};