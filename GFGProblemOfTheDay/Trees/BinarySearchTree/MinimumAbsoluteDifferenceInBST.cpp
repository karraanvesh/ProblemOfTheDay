// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1

class Solution
{
    public:
    int absolute_diff(Node *root)
    {
        stack<Node*> st;
        
        int minDiff = INT_MAX;
        bool flag = false;
        int prevEle = -1;
        
        Node *node = root;
        
        while(node != NULL or !st.empty()) {
            
            while(node != NULL) {
                st.push(node);
                node = node->left;
            }
            
            Node *currNode = st.top();
            
            st.pop();
            
            int currEle = currNode->data;
            
            if(!flag) {
                prevEle = currEle;
                flag = true;
            }
            
            else {
                int diff = abs(prevEle - currEle);
                minDiff = min(minDiff , diff);
                prevEle = currEle;
            }
            
            node = node;
            
            if(currNode->right)
            node = currNode->right;
        }
        
        return minDiff;
    }
};