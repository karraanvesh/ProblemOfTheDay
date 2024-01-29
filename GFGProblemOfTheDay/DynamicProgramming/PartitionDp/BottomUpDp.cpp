// Time Complexity : O(n * n * sum)
// Space Complexity : O(n * sum)


class Solution{
	public:
	int TotalCount(string str){
	    int sum = 0;
	    int n = str.length();
	    
	    for(int i = 0 ; i < n ; i++) {
	        sum += (str[i] - '0');
	    }
	    
	    vector<vector<int>> dp(n+1 , vector<int>(sum+1 , 0));
	    
	    for(int prevSum = 0 ; prevSum <= sum ; prevSum++) {
	        dp[n][prevSum] = 1;
	    }
	    
	    for(int ind = n-1 ; ind >= 0 ; ind--) {
	        
	        for(int prevSum = 0 ; prevSum <= sum ; prevSum++) {
	            int result , currSum;
                result = currSum = 0;
                
                for(int i = ind ; i < n ; i++) {
                    
                    currSum += (str[i] - '0');
                    
                    if(currSum >= prevSum) {
                        int noOfGroups = dp[i+1][currSum];
                        result += noOfGroups;
                    }
                }
                
                dp[ind][prevSum] = result;
	        }
	    }
	    return dp[0][0];
	}

};