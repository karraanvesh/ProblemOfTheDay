// Time  Complexity : O(n)
// Space Complexity : O(h) ~ O(n)
// where h is the height of the tree 

// Problem Link : https://www.geeksforgeeks.org/problems/ancestors-in-binary-tree/1

class Solution {
    private :
    void f(Node *root , vector<int> &path , int target , vector<int> &result) {
        
        if(!root) return ;
        
        if(root->data == target)
        result = path;
        
        path.push_back(root->data);
        
        f(root->left , path , target , result);
        f(root->right , path , target , result);
        
        path.pop_back();
        
        return ;
    }
  public:
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {
        vector<int> path , result;
        
        f(root , path , target , result);
        
        reverse(result.begin() , result.end());
        
        return result;
    }
};