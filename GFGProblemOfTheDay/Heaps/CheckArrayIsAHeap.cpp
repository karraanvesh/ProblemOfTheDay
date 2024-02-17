// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        for(int i = n/2 - 1 ; i >= 0 ; i--) {
            int leftChild = 2*i + 1;
            int rightChild = 2*i + 2;
            
            if(!(arr[i] >= arr[leftChild] and arr[i] >= arr[rightChild]))
            return false;
        }
        
        return true;
    }
};