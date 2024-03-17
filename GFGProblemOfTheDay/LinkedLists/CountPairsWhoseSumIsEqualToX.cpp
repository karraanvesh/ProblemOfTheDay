// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1

class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        unordered_map<int,int> mp;
        
        Node *ptr = head1;
        
        while(ptr != NULL) {
            int ele = ptr->data;
            
            mp[ele] = 1;
            ptr = ptr->next;
        }
        
        Node *ptr1 = head2;
        int noOfPairs = 0;
        
        while(ptr1 != NULL) {
            int currEle = ptr1->data;
            int diff = x - currEle;
            
            if(mp[diff]) {
                noOfPairs++;
            }
            
            ptr1 = ptr1->next;
        }
        
        return noOfPairs;
    }
};