// Time  Complexity : O(3 * n) ~ O(n)
// Space Complexity : O(2 * n) ~ O(n)

// Problem Link : https://leetcode.com/problems/trapping-rain-water/description/?envType=daily-question&envId=2024-04-12

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> leftMax(n , 0) , rightMax(n , 0);
        
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];
        
        for(int i = 1 ; i < n ; i++)    {
            leftMax[i] = max(leftMax[i-1] , height[i]);
            
            rightMax[n - i - 1] = max(rightMax[n - i] , height[n - i - 1]);
        }
        
        for(int i = 0 ; i < n ; i++)    {
            cout << leftMax[i] << " ";
        }
        
        cout << endl;
        for(int i = 0 ; i < n ; i++)    {
            cout << rightMax[i] << " ";
        }
        cout << endl;
        int trappedWater = 0;
        
        for(int i = 0 ; i < n ; i++)    {
            int mini = min(leftMax[i] , rightMax[i]);
            
            trappedWater += (mini - height[i]);
            
            cout << (mini - height[i]) << " " ;
        }
        
        return trappedWater;
    }
};