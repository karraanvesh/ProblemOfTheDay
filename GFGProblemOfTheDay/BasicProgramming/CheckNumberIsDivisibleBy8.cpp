// Time  Complexity : O(1)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/check-if-a-number-is-divisible-by-83957/1

class Solution{
    public:
    int DivisibleByEight(string s){
        int n = s.length();
        int num = 0;
        
        if(n == 1) {
            if(s[0] == '8')
            return 1;
            
            return -1;
        }
        
        else if(n == 2) {
            num = num*10 + s[0] - '0';
            num = num *10 + s[1] - '0';
            
            if(num%8 == 0) return 1;
            
            return -1;
        }
        
        else  {
            num = num*10 + s[n-3] - '0';
            num = num*10 + s[n-2] - '0';
            num = num*10 + s[n-1] - '0';
            
            if(num%8 == 0) return 1;
            
            return -1;
        }
        
        return -1;
    }
};