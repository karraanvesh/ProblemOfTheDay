// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1

vector<int> reverseLevelOrder(Node *root)
{
    map<int , vector<int>> mp;
    queue<pair<Node* , int>> q;
    vector<int> result;
    
    q.push({root , 0});
    
    while(!q.empty()) {
        Node *currNode = q.front().first;
        int level = q.front().second;
        
        q.pop();
        
        mp[level].push_back(currNode->data);
        
        if(currNode->left)
        q.push({currNode->left , level + 1});
        
        if(currNode->right)
        q.push({currNode->right , level + 1});
    }
    
    map<int , vector<int>> :: iterator itr;
    itr = mp.end();
    
    itr--;
    
    while(true) {
        vector<int> v = itr->second;
        int level = itr->first;
        
        int n = v.size();
        
        for(int i = 0 ; i < n ; i++) {
            result.push_back(v[i]);
        }
        
        itr--;
        
        if(level == 0)
        break;
    
    }
    
    return result;
}