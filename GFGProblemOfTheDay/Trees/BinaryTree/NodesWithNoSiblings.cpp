// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1

void dfs(Node *root , vector<int> &result) {
    
    if(root == NULL) return ;
    
    if(!root->left and !root->right) return ;
    
    if(root->left == NULL or root->right == NULL) {
        
        if(root->left == NULL)
        result.push_back(root->right->data);
        
        if(root->right == NULL)
        result.push_back(root->left->data);
    }
    
    dfs(root->left , result);
    dfs(root->right , result);
    
    return ;
}
vector<int> noSibling(Node* root)
{
    vector<int> result;
    
    dfs(root , result);
    
    if(result.size() == 0)
    result.push_back(-1);
    
    sort(result.begin() , result.end());
    
    return result;
}