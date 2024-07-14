// Time  Complexity : O(n * n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=daily-question&envId=2024-07-08

class Solution {
public:
    int findTheWinner(int n, int k) {
        int prevInd = -1;
        vector<int> arr(n , 0);
        
        for(int i = 1 ; i <= n ; i++)    {
            arr[i-1] = i;
        }
        
        while(arr.size() > 0) {
            
            int n = arr.size();
            int removedInd = (prevInd + k)%n;
            
            vector<int> vect;
            
            for(int i = 0 ; i < n ; i++)      {
                if(i != removedInd)
                    vect.push_back(arr[i]);
            }
            
            prevInd = removedInd - 1;
            
            arr = vect;
        }
        
        return arr[0];
    }
};