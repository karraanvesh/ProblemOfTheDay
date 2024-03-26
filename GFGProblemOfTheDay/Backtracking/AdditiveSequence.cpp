// Time  Complexity : O(n ^ 3)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/additive-sequence/1

class Solution {
    private :
    bool findAdditiveSeq(string &str , int ind , int n, vector<long> &arr) {
        int m = arr.size();
        
        if(ind == n) {
            
            if(arr.size() >= 3 and arr[m-1] == (arr[m-2] + arr[m-3])) return true;
            
            return false;
        }
        
        long prev1 , prev2 , sum , num;
        sum = num = prev1 = prev2 = 0;
        
        
        
        if(arr.size() >= 2) {
            prev1 = arr[m - 1];
            prev2 = arr[m - 2];
            sum = prev1 + prev2;
        }
        
        for(int i = ind ; i < n ; i++) {
            
            
            num = num * 10 + (str[i] - '0');
            
            if(m >= 2 and num == sum) {
                
                arr.push_back(num);
                
                if(findAdditiveSeq(str , i + 1 , n , arr))
                return true;
                
                arr.pop_back();
            }
            
            else if(m >= 2 and num > sum)
            break;
            
            else if(m < 2) {
                arr.push_back(num);
                
                if(findAdditiveSeq(str , i + 1 , n , arr))
                return true;
                
                arr.pop_back();
            }
            
        }
        
        return false;
    }
  public:
    bool isAdditiveSequence(string str) {
        vector<long> arr;
        
        int n = str.length();
        
        bool result = findAdditiveSeq(str , 0 , n , arr);
        
        return result;
    }
};