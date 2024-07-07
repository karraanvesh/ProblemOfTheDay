// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2024-07-01

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        
        int oddCt = 0;
        bool result = false;
        
        for(int i = 0 ; i < n ; i++)    {
            if(arr[i]%2 == 1) {
                oddCt++;
                
                if(oddCt == 3) {
                    result = true;
                    break;
                }
            }
            
            else 
                oddCt = 0;
        }
        
        return result;
    }
};