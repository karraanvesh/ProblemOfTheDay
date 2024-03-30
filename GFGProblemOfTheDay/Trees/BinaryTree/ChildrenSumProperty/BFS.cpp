// Time  Complexity : O(n)
// Space Complexity : O(n) 

class Solution{
    private :
    int result;
    
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if(root == NULL or (!root->left and !root->right)) return 1;
    
        result = 1;
        
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            Node *currNode = q.front();
            
            q.pop();
            
            int childSum = 0;
            
            if(!currNode->left and !currNode->right) {
                continue;
            }
            
            if(currNode->left) {
                childSum += currNode->left->data;
                q.push(currNode->left);
            }
            
            if(currNode->right) {
                childSum += currNode->right->data;
                q.push(currNode->right);
            }
            
            int currData = currNode->data;
            
            if(currData != childSum) {
                result = 0;
                break;
            }
        }
        
        return result;
    }
};