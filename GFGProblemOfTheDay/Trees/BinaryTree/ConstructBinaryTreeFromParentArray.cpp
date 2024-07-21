/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Time  Complexity : O(n * logn)
// Space Complexity : O(n + 2*(n - 1))

// Problem Link : https://www.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1

class Solution {
    private:
    Node* dfs(int node , vector<int> adj[] , set<int> &st) {
        
        Node *newNode = new Node(node);
        
        for(int &neigh : adj[node]) {
            
            if(st.count(neigh) == 0) {
                
                st.insert(neigh);
                if(newNode->left == NULL)
                newNode->left = dfs(neigh , adj , st);
                
                else if(newNode->right == NULL)
                newNode->right = dfs(neigh , adj , st);
            }
        }
        
        return newNode;
    }
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        int n = parent.size();
        vector<int> adj[n];
        
        int src = -1;
        
        for(int i = 0 ; i < n ; i++) {
            
            if(parent[i] == -1) {
                src = i;
                continue;
            }
            
            int u = i;
            int v = parent[i];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        set<int> st;
        st.insert(src);
        
        return dfs(src , adj , st);
    }
};
