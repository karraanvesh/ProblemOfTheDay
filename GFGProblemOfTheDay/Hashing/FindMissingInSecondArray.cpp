// Time Complexity : O(n + m)
// Space Complexity : O(m)

// Problem Link : https://www.geeksforgeeks.org/problems/in-first-but-second5423/1

class Solution{
	public:
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    set<int> st;
	    
	    for(int i = 0 ; i < m ; i++) {
	        st.insert(b[i]);
	    }
	    
	    vector<int> result;
	    
	    for(int i = 0 ; i < n ; i++) {
	        int ele = a[i];
	        
	        if(st.count(ele) == 0) {
	            result.push_back(ele);
	        }
	    }
	    
	    return result;
	} 
};