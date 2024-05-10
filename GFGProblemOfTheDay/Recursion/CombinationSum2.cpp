// Time  Complexity : O(2 ^ min(n , k))
// Space Complexity : O(unique_combinations)

// Problem Link : https://www.geeksforgeeks.org/problems/combination-sum-ii-1664263832/1

class Solution{
    private :
    void f(vector<int> &arr , int ind , int k , vector<vector<int>> &result , vector<int> &vect , 
    set<vector<int>> &st) {
        
        if(ind == -1) {
            if(k != 0) return ;
            
            vector<int> temp = vect;
            
            sort(temp.begin() , temp.end());
            
            if(st.count(temp) == 0) {
                st.insert(temp);
                result.push_back(temp);
            }
            
            return ;
        }
        
        
        if(arr[ind] <= k) {
            vect.push_back(arr[ind]);
            f(arr , ind - 1 , k - arr[ind] , result , vect , st);
            vect.pop_back();
        }
        
        f(arr , ind - 1 , k , result , vect , st);
        
        return ;
    }
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        vector<vector<int>> result;
        vector<int> vect;
        set<vector<int>> st;
        
        f(arr , n - 1 , k , result , vect , st);
        
        sort(result.begin() , result.end());
        
        return result;
    }
};