// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/alone-in-couple5507/1

class Solution{
    public:
    int findSingle(int n, int arr[]){
        
        if(n == 1)
        return arr[0];
        
        int result = 0;
        
        for(int i = 0 ; i < n ; i++) {
            result = result ^ arr[i];
        }
        
        return result;
    }
};