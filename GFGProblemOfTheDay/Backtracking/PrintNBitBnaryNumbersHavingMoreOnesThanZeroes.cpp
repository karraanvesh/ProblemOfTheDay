// Time Complexity : O(2 ^ n )
// Space Complexity : O(x)
// where x are the no of strings with more 1's in the prefix 

// Problem Link : https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

class Solution{
    private :
    void generateString(int n , string &str , int noOfOnes , int noOfZeroes , 
    vector<string> &result) {
        
        if(n == 0) {
            if(noOfOnes >= noOfZeroes)
            result.push_back(str);
            
            return ;
        }
        
        str += '1';
        generateString(n - 1 , str , noOfOnes + 1 , noOfZeroes , result);
        
        str.pop_back();
        
        if(noOfZeroes < noOfOnes) {
        
            str += '0';
            generateString(n - 1 , str , noOfOnes , noOfZeroes + 1 , result);
            
            str.pop_back();
        }
        
        return ;
    }
public:	
	vector<string> NBitBinary(int n)
	{
	    vector<string> result;
	    
	    string str;
	    
	    generateString(n, str , 0 , 0 , result);
	    
	    sort(result.begin() , result.end());
	    
	    reverse(result.begin() , result.end());
	    
	    return result;
	}
};