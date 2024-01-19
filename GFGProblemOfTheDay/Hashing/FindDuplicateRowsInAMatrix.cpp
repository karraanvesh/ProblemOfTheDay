// Time Complexity  : O(NlogN)
// Space Complexity : O(N*M)
// where N is the number of rows and M are the number of columns 

// Problem Link : https://www.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/1

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    {
        swap(N , M);
        
        set<vector<int>> st;
        vector<int> result;
        
        for(int i = 0 ; i < N ; i++) {
            
            if(st.count(matrix[i]) == 0) {
                st.insert(matrix[i]);
            } else {
                result.push_back(i);
            }
        }
        
        return result;
    } 
};