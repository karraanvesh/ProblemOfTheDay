// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/check-frequencies4211/1

class Solution{
public:	
	bool sameFreq(string s)
	{
	    int n = s.length();
	    vector<int> mp(26 , 0);
	    set<int> st;
	    
	    for(int i = 0 ; i < n ; i++) {
	        int currChar = s[i] - 'a';
	        
	        mp[currChar]++;
	    }
	    
	    vector<int> brr;
	    for(int i = 0 ; i < 26 ; i++) {
	        
	        if(mp[i]) {
	            brr.push_back(mp[i]);
	            st.insert(mp[i]);
	        }
	    }
	    
	    int distinctFreqCount = st.size();
	    
	    if(distinctFreqCount == 1) {
	        // either s contains only one character or 
	        // all characters in s have same frequency 
	        
	        return true;
	    }
	    
	    if(distinctFreqCount > 2) return false;
	    
	    set<int> :: iterator itr1 , itr2;
	    
	    itr1 = st.begin();
	    itr2 = itr1;
	    itr2++;
	    
	    int freq1 = *itr1 , freq2 = *itr2;
	    int diff = abs(freq1 - freq2);
	    
	    sort(brr.begin() , brr.end());
	    
	    int m = brr.size();
	    
	    if(brr[m-1] != brr[m-2] and diff == 1) return true;
	    
	    return false;
	}
};