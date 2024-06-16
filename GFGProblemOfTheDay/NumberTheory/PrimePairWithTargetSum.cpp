// Time  Complexity : O(n * loglogn)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/sum-of-prime4751/1

class Solution {
  public:
    vector<int> getPrimes(int n) {
        vector<int> sieve(n+1 , 1);
        
        for(int i = 2 ; i*i <= n ; i++) {
            
            if(sieve[i]) {
                for(int j = i*i ; j <= n ; j += i) {
                    sieve[j] = 0;
                }
            }
        }
        
        int i , j;
        i = 2;
        j = n;
        
        while(i <= j) {
            
            if(!sieve[i] or !sieve[j]) {
                
                if(!sieve[i])
                i++;
                
                if(!sieve[j])
                j--;
                
                continue;
            }
            
            int sum = i + j;
            
            if(sum > n) {
                j--;
            }
            
            else if(sum < n) {
                i++;
            }
            
            else if(sum == n) {
                vector<int> result;
                
                result.push_back(i);
                result.push_back(j);
                
                return result;
            }
        }
        
        vector<int> result(2 , -1);
        
        return result;
    }
};