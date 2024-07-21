// User function Template for C++

// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1

class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        
        if(n == 1) return arr[0];
        
        int i = 0;
        long long prod = 1 , mod = 1e9 + 7;
        long maxi = INT_MIN , negCount , posCount;
        negCount = posCount = 0;
        
        while(i < n) {
            
            if(arr[i] == 0) {
                i++;
                continue;
            }
            
            prod = (prod%mod * arr[i]%mod)%mod;
            
            if(arr[i] < 0) {
                negCount++;
                
                if(arr[i] > maxi)
                maxi = arr[i];
            } else {
                posCount++;
            }
            
            i++;
        }
        
        if((posCount + negCount) == 0 or (posCount == 0 and negCount == 1 and n > 1)) {
            prod = 0;
            
            return prod;
        }
        
        if(negCount%2 == 1) {
            prod = prod * -1;
            maxi = maxi * -1;
            
            prod = prod / maxi;
        }
        
        return prod;
    }
};
