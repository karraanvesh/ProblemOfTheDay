// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1

class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        map<int , int> mp;
        int result = -1;
        
        for(int i = 0 ; i < n ; i++) {
            mp[a[i]]++;
            
            int freq = mp[a[i]];
            
            if(freq >= k) {
                result = a[i];
                break;
            }
        }
        
        return result;
    }
};