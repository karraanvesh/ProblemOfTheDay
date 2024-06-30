// Time  Complexity : O(n * m)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/toeplitz-matrix/1

bool isValid(int row , int col , int n , int  m , bool &result , vector<vector<int>> &mat) {
    
    int val = mat[row][col];
        
    while(row < n and col < m) {
        
        if(mat[row][col] != val)
        result = false;
        
        row++;
        col++;
    }
    
    return result;
}
bool isToeplitz(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    bool result = true;
    
    for(int i = 0 ; i < n ; i++) {
        
        if(!isValid(i , 0 , n , m , result , mat)) return result;
    }
    
    for(int j = 1 ; j < m ; j++) {
        
        if(!isValid(0 , j , n , m , result , mat)) return result;
    }
    
    return result;
    
}