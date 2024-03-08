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
	    
	    if(distinctFreqCount > 2) {
            // s contains more than 2 characters with different 
            // frequencies like [ 2 , 3 , 4] or [4 , 6 , 7] etc 
            // removing 1 character doesn't make all frequencies 
            // equal 

            return false;
        }

        /*
            s contains only 2 characters or all the characters in s 
            have only 2 distinct frequencies . But we can only make 
            all the frequencies to be equal if maximum freq is 
            repeated for only once and smaller may be repeated any 
            number of times i.e., cases like [2 , 2 , 3] or [ 2 , 3] 
            or [4 , 4 , 4 , 4 , 5] etc . 

            But cases like [2 , 3 , 3] cannot be made equal because 
            here maximum  repeats for more than once , so we require 
            more than one operation or number of times maximum had occured 
            to make two frequencies equal 
        */
	    
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