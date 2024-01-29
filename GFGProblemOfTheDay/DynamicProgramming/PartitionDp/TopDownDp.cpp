// Time Complexity : O(n * n * sum)
// Space Complexity : O(n * sum) + O(n) (for auxilary stack space)

// Problem Link : https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1

class Solution{
    private :
    int f(string &str , int ind , int prevSum , int n , vector<vector<int>> &dp) {
        
        if(ind == n) return 1;
        
        if(dp[ind][prevSum] != -1) return dp[ind][prevSum];
        
        int result , currSum;
        result = currSum = 0;
        
        for(int i = ind ; i < n ; i++) {
            
            currSum += (str[i] - '0');
            
            if(currSum >= prevSum) {
                int noOfGroups = f(str , i+1 , currSum , n , dp);
                result += noOfGroups;
            }
        }
        
        return dp[ind][prevSum] = result;
    }
	public:
	int TotalCount(string str){
	    int sum = 0;
	    int n = str.length();
	    
	    for(int i = 0 ; i < n ; i++) {
	        sum += (str[i] - '0');
	    }
	    
	    vector<vector<int>> dp(n , vector<int>(sum+1 , -1));
	    return f(str , 0 , 0 , n , dp);
	}

};