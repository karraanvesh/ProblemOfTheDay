// Time  Complexity : O(3 * n) ~ O(n)
// Space Complexity : O(2 * n) ~ O(n)

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
    	
    	vector<long long> prev(n+1 , 0);
    	prev[0] = 1;
    	
    	for(int val = 0 ; val <= n ; val++) {
    	    
    	    if(val%arr[0] == 0)
    	    prev[val] = 1;
    	}
    	
    	for(int ind = 1 ; ind < 3 ; ind++) {
    	    vector<long long> curr(n+1 , 0);
    	    curr[0] = 1;
    	    
    	    for(int val = 1 ; val <= n ; val++) {
    	        
    	        long long pick = 0 , unpick;
        
                if(arr[ind] <= val)
                pick = curr[val - arr[ind]];
                
                unpick = prev[val];
                
                curr[val] = pick + unpick;
    	    }
    	    
    	    prev = curr;
    	}
    	
    	return prev[n];
    }
};