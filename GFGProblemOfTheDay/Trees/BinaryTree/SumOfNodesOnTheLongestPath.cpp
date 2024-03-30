// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

class Solution
{
    private :
    void pathSum(Node *root , int &sum , int &maxSum , int level , int &maxLevel) {
        if(root == NULL) return ;
        
        sum += root->data;
        
        pathSum(root->left , sum , maxSum , level + 1 , maxLevel);
        pathSum(root->right , sum , maxSum , level + 1 , maxLevel);
        
        if(!root->left and !root->right) {
            if(level > maxLevel) {
                maxLevel = level;
                maxSum = sum;
            }
            
            else if(level == maxLevel) {
                if(sum > maxSum)
                maxSum = sum;
            }
        }
        
        sum -= root->data;
        
        return ;
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int maxSum , sum , maxLevel;
        maxLevel = maxSum = sum = 0;
        
        pathSum(root , sum , maxSum , 1 , maxLevel);
        
        return maxSum;
    }
};