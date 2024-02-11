// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/recamans-sequence4856/1

class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int> recSeq(n+1 , 0);
        
        set<int> st;
        st.insert(0);
        
        if(n == 1) return recSeq;
        
        for(int i = 1 ; i < n ; i++) {
            int nextEle = recSeq[i-1] - i;
            
            if(nextEle > 0 and st.count(nextEle) == 0) {
                recSeq[i] = nextEle;
            }
            
            else {
                nextEle = recSeq[i-1] + i;
                recSeq[i] = nextEle;
            }
            
            st.insert(nextEle);
        }
        
        return recSeq;
    }
};