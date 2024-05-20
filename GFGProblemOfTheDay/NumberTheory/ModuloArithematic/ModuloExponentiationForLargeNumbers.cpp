// Time  Complexity : O(log n)
// Space Complexity : O(log n)

// Problem Link : https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1

class Solution
{
    private :
    long long f(long long a , long long b , long long M) {
        
        if(b == 0) return 1;
        
        if(b == 1) return a;
        
        long long x = f(a , b / 2 , M);
        
        if(b%2 == 0) {
            return (x%M * x%M)%M;
        }
        
        return (x%M * x%M * a%M)%M;
    }
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    return f(x , n , M);
		}
};