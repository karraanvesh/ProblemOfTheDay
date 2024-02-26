// Time Complexity : O(2 ^ n)
// Space Complexity : O(2 ^ n)

// Problem Link : https://www.geeksforgeeks.org/problems/power-set4302/1

class Solution{
    private :
    void generatePowerSet(int ind , int n , string &str , string &currStr , vector<string> &result) {
        
        if(ind == n) {
            if(currStr.size() > 0)
            result.push_back(currStr);
            return ;
        }
        
        currStr += str[ind];
        generatePowerSet(ind + 1 , n , str , currStr , result);
        
        currStr.pop_back();
        
        generatePowerSet(ind + 1 , n , str , currStr , result);
        
        return ;
    }
	public:
		vector<string> AllPossibleStrings(string str){
		    int n = str.length();
		    vector<string> result;
		    
		    string s;
		    
		    generatePowerSet(0 , n , str , s , result);
		    
		    sort(result.begin() , result.end());
		    
		    return result;
		}
};