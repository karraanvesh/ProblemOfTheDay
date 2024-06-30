// Time  Complexity : O(n * m)
// Space Complexity : O(m)

// Problem Link : https://www.geeksforgeeks.org/problems/left-rotate-matrix-k-times2351/1

class Solution {
    private : 
    vector<int> leftRotation(vector<int> &vect , int n , int k) {
        
        vector<int> arr , brr;
        
        for(int i = 0 ; i < k ; i++) {
            arr.push_back(vect[i]);
        }
        
        for(int i = k ; i < n ; i++) {
            brr.push_back(vect[i]);
        }
        
        reverse(arr.begin() , arr.end());
        reverse(brr.begin() , brr.end());
        
        vector<int> result;
        
        int i , j;
        i = j = 0;
        
        while(i < arr.size()) {
            result.push_back(arr[i]);
            i++;
        }
        
        while(j < brr.size()) {
            result.push_back(brr[j]);
            j++;
        }
        
        reverse(result.begin() , result.end());
        
        return result;
    }
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        k = k%m;
        
        if(k == 0)
        return mat;
        
        for(int i = 0 ; i < n ; i++) {
            mat[i] = leftRotation(mat[i] , m , k);
        }
        
        return mat;
    }
};