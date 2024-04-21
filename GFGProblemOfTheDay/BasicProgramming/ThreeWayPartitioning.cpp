// Time  Complexity : O(3 * n) ~ O(n)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/three-way-partitioning/1

class Solution{   
    private :
    void partitionHelper(vector<int> &arr , vector<int> &result , int low , int high) {
        
        int n = arr.size();
        
        for(int i = 0 ; i < n ; i++) {
            
            if(arr[i] >= low and arr[i] <= high)
            result.push_back(arr[i]);
        }
        
        return ;
    }
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        vector<int> result;
        int n = arr.size();
        
        partitionHelper(arr , result , 0 , a - 1);
        partitionHelper(arr , result , a , b);
        partitionHelper(arr , result , b+1 , INT_MAX);
        
        arr = result;
        
        return ;
    }
};