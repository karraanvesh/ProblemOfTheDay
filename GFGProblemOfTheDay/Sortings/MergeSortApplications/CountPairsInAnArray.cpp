// Time Complexity : O(n * logn)
// Space Complexity : O(n) + O(logn) (for auxilary stack space)

// Problem Link : https://www.geeksforgeeks.org/problems/count-pairs-in-an-array4145/1

class Solution{
    private :
    int merge(int arr[] , int low , int mid , int high) {
        int i = low , j = mid + 1;
        vector<int> brr;
        int inversionCount = 0;
        
        while(i <= mid and j <= high) {
            
            if(arr[i] <= arr[j]) {
                brr.push_back(arr[i]);
                i++;
            }
            
            else {
                int ct = (mid - i) + 1;
                inversionCount += ct;
                
                brr.push_back(arr[j]);
                j++;
            }
        }
        
        while(i <= mid) {
            brr.push_back(arr[i]);
            i++;
        }
        
        while(j <= high) {
            brr.push_back(arr[j]);
            j++;
        }
        
        for(int k = low ; k <= high ; k++) {
            arr[k] = brr[k - low];
        }
        
        return inversionCount;
    }
    int mergeSort(int arr[] , int low , int high) {
        if(low == high) return 0;
        
        int mid = low + (high - low) / 2;
        
        int leftHalf = mergeSort(arr , low , mid);
        int rightHalf = mergeSort(arr , mid + 1 , high);
        
        int result = merge(arr , low , mid , high);
        
        return (leftHalf + rightHalf + result);
    }
    public:
    int countPairs(int arr[] , int n ) 
    {
        for(int i = 0 ; i < n ; i++) {
            arr[i] = i * arr[i];
        }
        
        return mergeSort(arr , 0 , n - 1);
    }
};