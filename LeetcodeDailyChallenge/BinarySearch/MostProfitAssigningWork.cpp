// Time  Complexity : O(n * logn)
// Space Complexity : O(2 * n ) ~ O(n)

// Problem Link : https://leetcode.com/problems/most-profit-assigning-work/description/?envType=daily-question&envId=2024-06-18

class Solution {
    private :
    int upperBound(vector<pair<int , int>> &vect , int low , int high , int target) {

       while(low <= high) 
       {

           int mid = low + (high - low)/2;
           
           if(target < vect[mid].first)
               high = mid - 1;
           
           else 
               low = mid + 1;
       }
        
       return high;
}
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        
        vector<pair<int , int>> vect;
        
        for(int i = 0 ; i < n ; i++)    {
            vect.push_back({difficulty[i] , profit[i]});
        }
        
        sort(vect.begin() , vect.end());

        int m = worker.size();
        long maxProfit = 0;
        
        vector<int> arr(n, 0);
        arr[0] = vect[0].second;
        
        for(int i = 1 ; i < n ; i++)    {
            arr[i] = max(vect[i].second , arr[i-1]); 
        }

        for(int i = 0 ; i < m ; i++)    {
            int ind = upperBound(vect , 0 , n - 1 , worker[i]);
            
            if(ind == -1)
                continue;
             
            maxProfit += arr[ind];
            
        }
        
        return maxProfit;
    }
};