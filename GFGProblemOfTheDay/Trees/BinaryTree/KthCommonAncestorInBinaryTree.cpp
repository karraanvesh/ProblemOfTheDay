// Time  Complexity : O(n)
// Space Complexity : O(n)
// where n are the number of nodes in given tree 

// Problem Link : https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1

class Solution
{
    private :
    void lcaHelper(Node *root , int x , int y , vector<Node*> &path , vector<Node*> &v1 , vector<Node*> &v2) {
        
        if(root == NULL) return ;
        
        path.push_back(root);
        
        if(root->data == x) {
            v1 = path;
        }
        
        if(root->data == y) {
            v2 = path;
        }
        
        lcaHelper(root->left , x , y , path , v1 , v2);
        lcaHelper(root->right , x , y , path , v1 , v2);
        
        path.pop_back();
        
        return ;
    }
    public:
    
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        vector<Node*> path;
        
        vector<Node*> v1 , v2;
        
        lcaHelper(root , x , y , path , v1 , v2);
        
        while(v1.size() > v2.size()) {
            v1.pop_back();
        }
        
        while(v2.size() > v1.size()) {
            v2.pop_back();
        }
        
        while(v1.size() and v2.size()) {
            Node *p = v1[v1.size() - 1];
            Node *q = v2[v2.size() - 1];
            
            if(p == q)
            break;
            
            v1.pop_back();
            v2.pop_back();
        }
        
        int n = v1.size();
        
        if(n < k) return -1;
        
        int result = v1[n - k]->data;
        
        return result;
        
    }
};