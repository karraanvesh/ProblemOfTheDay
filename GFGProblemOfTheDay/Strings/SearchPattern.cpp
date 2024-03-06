// Time  Complexity : O(n * m)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1

class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            vector<int> result;
            int n = text.length();
            int m = pattern.length();
            
            for(int i = 0 ; i <= n-m ; i++) {
                string str = text.substr(i , m);
                
                if(str.compare(pattern) == 0) {
                    result.push_back(i+1);
                }
            }
            
            return result;    
        } 
};