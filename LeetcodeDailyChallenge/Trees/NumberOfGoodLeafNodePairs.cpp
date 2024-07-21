/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Time  Complexity : O(n)
// Space Complexity : O(maximum_width_of_a_tree)

// Problem Link : https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/?envType=daily-question&envId=2024-07-18

class Solution {
    private:
    void f(TreeNode* root , map<TreeNode* , TreeNode*> &mp , vector<TreeNode*> &leafs) {
        
        TreeNode *node = root;
        
        queue<TreeNode*> q;
        q.push(node);
        
        mp.insert({node , NULL});
        
        while(!q.empty()) {
            
            TreeNode *currNode = q.front();
            
            q.pop();
            
            if(currNode->left) {
                q.push(currNode->left);
                mp.insert({currNode->left , currNode});
            }
            
            if(currNode->right) {
                q.push(currNode->right);
                mp.insert({currNode->right , currNode});
            }
            
            if(!currNode->left and !currNode->right) {
                leafs.push_back(currNode);
            }
        }
        
        return ;
    }
    
    void goodPairs(TreeNode *root , map<TreeNode* , TreeNode*> &mp , set<TreeNode*> &st , int &result , int target)
    {
        TreeNode *node = root;
        
        queue<pair<TreeNode* , int>> q;
        
        q.push({node , 0});
        
        set<TreeNode*> visited;
        visited.insert(node);
        
        while(!q.empty()) {
            
            TreeNode *currNode = q.front().first;
            int dist = q.front().second;
            
            q.pop();

            if(dist > target) continue;
            
            TreeNode *par , *leftChild , *rightChild;
            
            par = mp[currNode];
            leftChild = currNode->left;
            rightChild = currNode->right;
            
            if(par and visited.count(par) == 0) {
                q.push({par , dist + 1});
                visited.insert(par);
            }
            
            if(leftChild and visited.count(leftChild) == 0) {
                q.push({leftChild , dist + 1});
                visited.insert(leftChild);
            }
            
            if(rightChild and visited.count(rightChild) == 0) {
                q.push({rightChild , dist +1});
                visited.insert(rightChild);
            }
            
            if(!leftChild and !rightChild and st.count(currNode) == 0) {
                
                if(dist <= target) {
                    result++;
                }
            }
        }

    }
public:
    int countPairs(TreeNode* root, int distance) {
        map<TreeNode* , TreeNode*> mp;
        
        vector<TreeNode*> leafs;
       
        f(root , mp ,leafs);
        
        int noOfLeafs = leafs.size();
        
        set<TreeNode*> st;
        int result = 0;
        
        for(int i = 0 ; i < noOfLeafs ; i++) {

            st.insert(leafs[i]);
            goodPairs(leafs[i] , mp , st , result , distance);
        }
        
        return result;
    }
};
