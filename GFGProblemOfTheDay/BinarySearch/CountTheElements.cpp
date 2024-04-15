// Time  Complexity : O(nlogn + q)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/count-the-elements1529/1

class Solution {
    private :
    int lowerBound(vector<int> &arr , int low , int high , int target) {
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(arr[mid] <= target)
            low = mid + 1;
            
            else
            high = mid - 1;
        }
        
        return low;
    }
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        sort(b.begin() , b.end());
        
        map<int , int> mp;
        
        for(int i = 0 ; i < n ; i++) {
            int lb = lowerBound(b , 0 , n - 1 , a[i]);
            mp[a[i]] = lb;
        }
        
        vector<int> result;
        
        for(int i = 0 ; i < q ; i++) {
            int ele = a[query[i]];
            
            int ans = mp[ele];
            result.push_back(ans);
        }
        
        return result;
    }
};