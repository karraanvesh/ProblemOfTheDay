// Time Complexity : O(3 * n * logn) ~ O(n * logn)
// Space Complexity : O(2 * n) ~ O(n)

// Problem Link : https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/?envType=daily-question&envId=2024-06-14

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        
        priority_queue<pair<long , long> , vector<pair<long , long>> , greater<pair<long , long>>> pq;
        
        map<long , long> mp;
        
        for(int i = 0 ; i < n ; i++)    {
            mp[nums[i]]++;
        }
        
        map<long , long> :: iterator itr;
        
        for(itr = mp.begin() ; itr != mp.end() ; itr++) {
            long ele = itr->first;
            long freq = itr->second;
            
            pq.push({ele , freq});
        }
        
        long minOp = 0;
        
        while(!pq.empty()) {
            long ele = pq.top().first;
            long freq = pq.top().second;
            
            pq.pop();
            
            if(freq == 1)
                continue;
            
            minOp += (freq - 1);
            
            long nextEle = pq.top().first;
            
            if(nextEle == (ele + 1))         {
                long nextFreq = pq.top().second;
                
                nextFreq += (freq - 1);
                
                pq.pop();
                pq.push({nextEle , nextFreq});
            }
            
            else {
                pq.push({ele + 1 , (freq - 1)});
            }
                
        }
        
        return minOp;
    }
};