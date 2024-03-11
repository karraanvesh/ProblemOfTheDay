// Time  Complexity : O(n * m)
// Space Complexity : O(n * m)

// Problem Link : https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1

class Solution{
public:	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    int noOfPairs = 0;
	    map<int , int> mp;
	    
	    for(int i = 0 ; i < n ; i++) {

	        for(int j = 0 ; j < n ; j++) {

	            int ele = mat1[i][j];
	            mp[ele]++;
	        }
	    }
	    
	    
	    for(int i = 0 ; i < n ; i++) {
	        
	        for(int j = 0 ; j < n ; j++) {
	            
	            int currEle = mat2[i][j];
	            
	            if(currEle <= x) {
	                int diff = x - currEle;
	                
	                int ct = mp[diff];
	                noOfPairs += ct;
	            }
	        }
	    }
	    
	    return noOfPairs;
	}
};