// Time Complexity : O(3 * n) ~ O(n)
// Space Complexity : O(3 * n) ~ O(n)

class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	vector<int> arr;
    	arr.push_back(3);
    	arr.push_back(5);
    	arr.push_back(10);
    	
    	vector<vector<long long>> dp(3 , vector<long long>(n+1 , 0));
    	
    	for(int val = 0 ; val <= n ; val++) {
    	    
    	    if(val%arr[0] == 0)
    	    dp[0][val] = 1;
    	}
    	
    	for(int ind = 0 ; ind < 3 ; ind++) {
    	    dp[ind][0] = 1;
    	}
    	
    	for(int ind = 1 ; ind < 3 ; ind++) {
    	    
    	    for(int val = 1 ; val <= n ; val++) {
    	        
    	        long long pick = 0 , unpick;
        
                if(arr[ind] <= val)
                pick = dp[ind][val - arr[ind]];
                
                unpick = dp[ind - 1][val];
                
                dp[ind][val] = pick + unpick;
    	    }
    	}
    	
    	return dp[2][n];
    }
};