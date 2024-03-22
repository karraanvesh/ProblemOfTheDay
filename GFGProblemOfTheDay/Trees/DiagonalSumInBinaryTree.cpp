// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1

class Solution
{
    public:
    vector <int> diagonalSum(Node* root) {
        map<int , int> mp;
        
        queue<pair<Node* , int>> q;
        q.push({root , 1});
        
        while(!q.empty()) {
            Node *currNode = q.front().first;
            int level = q.front().second;
            
            q.pop();
            
            mp[level] += currNode->data;
            
            if(currNode->left)
            q.push({currNode->left , level + 1});
            
            if(currNode->right)
            q.push({currNode->right , level});
        }
        
        vector<int> result;
        
        map<int , int> :: iterator itr;
        
        for(itr = mp.begin() ; itr != mp.end() ; itr++) {
            int sum = itr->second;
            result.push_back(sum);
        }
        
        return result;
    }
};