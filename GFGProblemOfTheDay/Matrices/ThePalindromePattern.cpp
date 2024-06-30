// Time  Complexity : O(2 * n * m) ~ O(n * m)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/the-palindrome-pattern3900/1

class Solution {
    private :
    string convertNumToStr(int num , string text) {
        
        vector<int> v;
        string str;
        
        if(num == 0)
        v.push_back(num);
        
        while(num > 0) {
            v.push_back(num%10);
            num /= 10;
        }
        
        reverse(v.begin() , v.end());
        
        for(int i = 0 ; i < v.size() ; i++) {
            
            str += '0' + v[i];
        }
        
        str += text;
        
        return str;
    }
  public:

    string pattern(vector<vector<int>> &arr) {
        int n = arr.size();
        string result = "-1";
        
        for(int i = 0 ; i < n ; i++) {
            
            int left , right;
            left = 0;
            right =  n - 1;
            bool flag = true;
            
            while(left < right) {
                
                if(arr[i][left] != arr[i][right])
                flag = false;
                
                left++;
                right--;
            }
            
            if(flag) {
                result = convertNumToStr(i , " R");
                
                return result;
            }
        }
            
        for(int i = 0 ; i < n ; i++) {
            
            int left , right;
            left = 0;
            right =  n - 1;
            bool flag = true;
            
            while(left < right) {
                
                if(arr[left][i] != arr[right][i])
                flag = false;
                
                left++;
                right--;
            }
            
            if(flag) {
                result = convertNumToStr(i , " C");
                
                return result;
            }
        }
        
        return result;
    }
};