// Time  Complexity : O(n * m)
// Space Complexity : O(2 * m) ~ O(m)

class Solution
{
    private :
    int mod = 1e9 + 7;
public:
    int ways(int x, int y)
    {
        int n = x + 1;
        int m = y + 1;
        
        vector<int> nextRow(m , 1);
        
        for(int i = n - 2 ; i >= 0 ; i--) {
            vector<int> currRow(m , 0);
            currRow[m - 1] = 1;
            
            for(int j = m - 2 ; j >= 0 ; j--) {
                
                int a = currRow[j + 1];
                int b = nextRow[j];
                
                currRow[j] = (a%mod + b%mod)%mod;
            }
            nextRow = currRow;
        }
        
        return nextRow[0];
    }
};