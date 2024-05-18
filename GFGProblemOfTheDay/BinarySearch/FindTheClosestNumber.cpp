// Time  Complexity : O(logn)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/find-the-closest-number5513/1

class Solution{
    private :
    int lowerBound(int arr[] , int n , int k) {
        int low = 0 , high = n - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(arr[mid] <= k)
            low = mid + 1;
            
            else
            high = mid - 1;
        }
        
        return arr[high];
    }
    
    int upperBound(int arr[] , int n , int k) {
        int low = 0 , high = n - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(arr[mid] >= k)
            high = mid - 1;
            
            else
            low = mid + 1;
        }
        
        return arr[low];
    }
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int lb = lowerBound(arr , n , k);
        int ub = upperBound(arr , n , k);
        
        int diff1 = k - lb;
        int diff2 = ub - k;
        
        if(diff1 == diff2) return ub;
        
        if(diff1 < diff2) return lb;
        
        return ub;
        
    } 
};