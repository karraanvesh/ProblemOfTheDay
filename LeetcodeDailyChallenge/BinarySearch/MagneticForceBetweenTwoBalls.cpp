// Time  Complexity: O(n * logx)
// Space Complexity : O(1)
// where x is the difference between the first ball and last ball position ( after sorting) 

// Problem Link : https://leetcode.com/problems/magnetic-force-between-two-balls/description/?envType=daily-question&envId=2024-06-20

class Solution {
    private :
    bool canWePlace(vector<int> &position , int n , int m , long dist) {
        long assignedBallCt = 1;
        long prevPos = position[0];
        
        for(int i = 1 ; i < n ; i++) {
            long currPos = position[i];
            
            long diff = currPos - prevPos;
            
            if(diff >= dist) {
                prevPos = currPos;
                assignedBallCt++;
            }
            
            if(assignedBallCt == m) {
                return true;
            }
        }
        
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        
        sort(position.begin() , position.end());
        
        int low = 1 , high;
        high = position[n-1] - position[0];
        
        while(low <= high) {
            long mid = low + (high - low)/2;
            
            if(canWePlace(position , n , m , mid))
            low = mid + 1;
            
            else 
            high = mid - 1;
        }
        
        return high;
    }
};