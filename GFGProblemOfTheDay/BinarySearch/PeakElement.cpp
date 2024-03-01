// Time Complexity : O(logn)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/peak-element/1

class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
        if(n == 1)
        return 0;
        
        if(arr[n-1] >= arr[n-2])
        return n-1;
        
        int low , high;
        low = 0;
        high = n-1;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(arr[mid] <= arr[mid+1])
            low = mid + 1;
            
            else
            high = mid - 1;
        }
        return low;
    }
};