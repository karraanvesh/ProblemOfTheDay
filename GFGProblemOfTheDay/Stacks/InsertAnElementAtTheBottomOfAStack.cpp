// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1

class Solution{
public:
    stack<int> insertAtBottom(stack<int> st,int x){
        stack<int> temp;
        
        while(!st.empty()) {
            int topEle = st.top();
            
            st.pop();
            
            temp.push(topEle);
        }
        
        st.push(x);
        
        while(!temp.empty()) {
            int topEle = temp.top();
            
            temp.pop();
            
            st.push(topEle);
        }
        
        return st;
    }
};