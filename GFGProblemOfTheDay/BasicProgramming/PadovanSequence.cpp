// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/padovan-sequence2855/1

class Solution
{
    public:
    int padovanSequence(int n)
    {
       if(n <= 2) return 1;
       
       int a , b , c, sum;
       a = b = c = 1;
       int mod = 1e9 + 7;
       
       for(int i = 3 ; i <= n ; i++) {
           sum = (a%mod + b%mod)%mod;
           
           a = b;
           b = c;
           c = sum;
       }
       
       return sum;
    }
    
};