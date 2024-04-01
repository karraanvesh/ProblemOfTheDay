// Time  Complexity : O(n * logn)
// Space Complexiy  : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1

class Solution {
    private :
    int result;
    
    void merge(vector<int> &arr , int low , int mid , int high) {
        int i = low , j = mid + 1;
        vector<int> brr;
        
        while(i <= mid and j <= high) {
            
            if(arr[i] <= arr[j]) {
                brr.push_back(arr[i]);
                i++;
            }
            
            else {
                int noOfPairs = (mid - i) + 1;
                result += noOfPairs;
                
                brr.push_back(arr[j]);
                
                j++;
            }
        }
        
        while(i <= mid) {
            brr.push_back(arr[i]);
            i++;
        }
        
        while(j <= high) {
            brr.push_back(arr[j]);
            j++;
        }
        
        
        for(int k = low ; k <= high ; k++) {
            arr[k] = brr[k - low];
        }
        
        return ;
    }
    void mergeSort(vector<int> &arr , int low , int high) {
        
        if(low == high) return ;
        
        int mid = low + (high - low) / 2;
        
        mergeSort(arr , low , mid);
        mergeSort(arr , mid + 1 , high);
        
        merge(arr , low , mid , high);
    }
  public:

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        
        vector<int> arr;
        
        stack<Node*> st;
        
        Node *node = root;
        
        while(node != NULL or !st.empty()) {
            
            
            while(node != NULL) {
                st.push(node);
                node = node->left;
            }
            
            Node *currNode = st.top();
            
            st.pop();
            
            arr.push_back(currNode->data);
            
            if(currNode->right)
            node = currNode->right;
        }
        
        result = 0;
        
        mergeSort(arr , 0 , n-1);
        
        return result;
    }
};