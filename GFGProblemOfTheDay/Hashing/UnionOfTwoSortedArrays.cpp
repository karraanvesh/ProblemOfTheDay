// Time  Complexity : O(n + m * log (n + m))
// Space Complexity : O(n + m)

// Problem Link : https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        set<int> st;
        
        int i , j;
        i = j = 0;
        
        vector<int> result;
        
        while(i < n and j < m) {
            
            if(arr1[i] <= arr2[j]) {
                
                if(st.count(arr1[i]) == 0) {
                    st.insert(arr1[i]);
                    result.push_back(arr1[i]);
                }
                
                i++;
            }
            
            else {
                
                if(st.count(arr2[j]) == 0) {
                    st.insert(arr2[j]);
                    result.push_back(arr2[j]);
                }
                
                j++;
            }
        }
        
        while(i < n) {
            if(st.count(arr1[i]) == 0) {
                st.insert(arr1[i]);
                result.push_back(arr1[i]);
            }
            
            i++;
        }
        
        while(j < m) {
            if(st.count(arr2[j]) == 0) {
                st.insert(arr2[j]);
                result.push_back(arr2[j]);
            }
            
            j++;
        }
        
        return result;
    }
};