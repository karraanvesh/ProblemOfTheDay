// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/compare-two-fractions4438/1

class Solution {
  public:
    string compareFrac(string str) {
        int n = str.length();
        
        int a , b , c , d;
        a = b = c = d = 0;
        
        int i = 0;
        string str1 , str2;
        
        while(str[i] != '/') {
            a = a*10 + (str[i] - '0');
            
            str1 += str[i];
            i++;
        }
        
        str1 += '/';
        
        i++;
        
        while(str[i] != ',') {
            b = b*10 + (str[i] - '0');
            
            str1 += str[i];
            i++;
        }
        
        i += 2;
        
        while(str[i] != '/') {
            c = c*10 + (str[i] - '0');
            
            str2 += str[i];
            i++;
        }
        
        str2 += '/';
        
        i++;
        
        while(i < n) {
            d = d*10 + (str[i] - '0');
            
            str2 += str[i];
            i++;
        }
        
        double val1 , val2;
        
        val1 = ((double) a / b);
        val2 = ((double) c / d);
        
        if(val1 > val2)
        return str1;
        
        else if(val2 > val1)
        return str2;
        
        return "equal";
    }
};