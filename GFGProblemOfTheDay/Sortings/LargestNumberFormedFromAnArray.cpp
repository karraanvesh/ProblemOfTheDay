// Time  Complexity : O(n * logn)
// Space Complexity : O(len)
// where len is the sum of individual strings in arr 

// Problem Link : https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

class Solution{
    private :
    static bool compare(string &s1 , string &s2) {
        string str1 = s1 + s2;
        string str2 = s2 + s1;
        
        return str1 > str2;
    }
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(int n, vector<string> &arr) {
	    
	    sort(arr.begin() , arr.end() , compare);
	    
	    string largestNum;
	    
	    for(int i = 0 ; i < n ; i++) {
	        largestNum += arr[i];
	    }
	    
	    return largestNum;
	}
};