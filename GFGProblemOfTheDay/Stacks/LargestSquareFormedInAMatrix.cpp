// Time  Complexity : O(2 * n * m) ~ O(n * m)
// Space Complexity : O(3 * m) ~ O(m)
// where m is the number of columns in the given matrix 

// Problem Link : https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

class Solution {
    private : 
    void nextSmaller(vector<int> &arr , vector<int> &smaller , bool flag , int ind) {
        stack<int> st;
        
        int i = ind;
        int n = arr.size();
        
        while(true) {
            
            while(!st.empty() and arr[i] < arr[st.top()]) {
                smaller[st.top()] = i;
                st.pop();
            }
            
           st.push(i);
           
           i = (flag) ? (i + 1) : (i - 1);
           
           if(i == n or i == -1)
           break;
        }
        
        return ;
    }
    void largestSquare(vector<int> &arr , int n , int &result) {
        
        vector<int> leftSmaller(n , -1) , rightSmaller(n , n);
        
        nextSmaller(arr , rightSmaller , true , 0);
        nextSmaller(arr , leftSmaller , false , n - 1);
        
        for(int i = 0 ; i < n ; i++) {
            
            int breath = arr[i];
            
            leftSmaller[i]++;
            rightSmaller[i]--;
            
            int length = (rightSmaller[i] - leftSmaller[i]) + 1;
            
            int side = min(length , breath);
            
            result = max(result, side);
        }
        
        return ;
    }
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        vector<vector<int>> grid(n , vector<int>(m , 0));
        
        int result = 0;
        
        for(int j = 0 ; j < m ; j++) {
            
            grid[n-1][j] = mat[n-1][j];
        }
        
        largestSquare(grid[n-1] , m ,result);
        
        for(int i = n-2 ; i >= 0 ; i--) {
            
            for(int j = 0 ; j < m ; j++) {
                
                if(mat[i][j] == 0) continue;
                
                grid[i][j] = grid[i+1][j] + 1;
            }
            
            largestSquare(grid[i] , m , result);
        }
        
        return result;
    }
};