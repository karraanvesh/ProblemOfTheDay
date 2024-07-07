// Time  Complexity: O(n)
// Space Complexity: O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        if(head->next == NULL)
        return head;
        
        Node *ptr = head , *nextNode = NULL;
        Node *newHead = NULL;
        Node *prevNode = NULL;
        
        while(ptr != NULL) {
            
            bool flag = false;
            nextNode = ptr->next;
            
            while(nextNode and ptr->data == nextNode->data) {
                flag = true;
                nextNode = nextNode->next;
            }
            
            if(!flag) {
                if(newHead == NULL) {
                    newHead = ptr;
                    prevNode = ptr;
                }
                
                else {
                    prevNode->next = ptr;
                    prevNode = ptr;
                }
            } 
            
            ptr = nextNode;
        }
        
        if(prevNode)
        prevNode->next = NULL;
        
        return newHead;
    }
};