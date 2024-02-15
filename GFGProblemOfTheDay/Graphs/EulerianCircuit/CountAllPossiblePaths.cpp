// Time  Complexity : O(n * n)
// Space Complexity : O(n * n)

// Problem Link : https://www.geeksforgeeks.org/problems/castle-run3644/1

class Solution {
public:
	int isPossible(vector<vector<int>>paths){
	    int n = paths.size();
	    
	    for(int i = 0 ; i < n ; i++) {
	        int degree = 0;
	        
	        for(int j = 0 ; j < n ; j++) {
	            
	            if(paths[i][j])
	            degree++;
	        }
	        
	        if(degree%2 == 1) return 0;
	    }
	    
	    return 1;
	}

};