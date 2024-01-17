// Time Complexity : O(n * m)
// Space Complexity : O(2 * m) ~ O(m)


class Solution{
public:
    int numberSequence(int m, int n){
        vector<int> prevRow(m+1 , 1);
        
        for(int temp = 1 ; temp <= n ; temp++) {
            
            vector<int> curr(m+1 , 0);
            
            for(int prev = 0 ; prev <= m ; prev++) {
                int seqCount = 0;
        
                int start = (prev == 0) ? 1 : 2*prev;
                
                for(int i = start ; i <= m ; i++) {
                    
                    int x = prevRow[i];
                    seqCount += x;
                }
            
                curr[prev] = seqCount;
            }
            
            prevRow = curr;
        }
        
        return prevRow[0];
    }
};