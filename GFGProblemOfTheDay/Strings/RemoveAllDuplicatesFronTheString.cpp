// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1

class Solution{
public:
	string removeDuplicates(string str) {
	    int n = str.length();
	    set<char> st;
	    string result;
	    
	    for(int i = 0 ; i < n ; i++) {
	        int freq = st.count(str[i]);
	        
	        if(freq == 0) {
	            result += str[i];
	        }
	        
	        st.insert(str[i]);
	    }
	    
	    return result;
	}
};