// Time Complexity  : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1

class Solution
{
    private :
    bool isUpperCase(char ch) {
        return (ch >= 'A' and ch <= 'Z');
    }
    bool isLowerCase(char ch) {
        return (ch >= 'a' and ch <= 'z');
    }
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string str) {
        int n = str.length();
        
        vector<int> mp(26 , 0);
        
        for(int i = 0 ; i < n ; i++) {
            char ch = str[i];
            
            if(isUpperCase(ch))
            ch = ch + 32;
            
            if(!isLowerCase(ch))
            continue;
            
            int currChar = ch - 'a';
            mp[currChar]++;
        }
        
        for(int i = 0 ; i < 26 ; i++) {
            if(mp[i] == 0)
            return 0;
        }
        
        return 1;
    }

};