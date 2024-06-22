// Time  Complexity: O(n * logx)
// Space Complexity : O(1)
// where x is the max_element in bloomDay 

// Problem Link : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/?envType=daily-question&envId=2024-06-19

class Solution {
    private : 
    bool isItPossible(vector<int> &bloomDay , int m , int k , int n , int currDay) {
        
        int ct , noOfBouquets;
        ct = noOfBouquets = 0;
        
        for(int i = 0 ; i < n ; i++) {

            if(bloomDay[i] > currDay) {
                ct = 0;
                continue;
            }
            
            ct++;
            
            if(ct == k) {
                noOfBouquets++;
                ct = 0;
            }
        }
        
        return (noOfBouquets >= m);
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        
        double reqFlowers = (double) m*k;
        
        if(reqFlowers > n) 
        return -1;
        
        int low , high;
        low = 1;
        high = *max_element(bloomDay.begin() , bloomDay.end());
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(isItPossible(bloomDay , m , k , n , mid))
            high = mid - 1;
            
            else 
            low = mid + 1;
        }
        
        return low;       
    }
};