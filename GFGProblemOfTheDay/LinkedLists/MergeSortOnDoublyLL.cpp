// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1

class Solution {
    private :
    Node* merge(Node *head1 , Node *head2) {
        Node *ptr1 = head1 , *ptr2 = head2;
        Node *prevNode , *head;
        head = prevNode = NULL;
        
        while(ptr1 != NULL and ptr2 != NULL) {
            
            if(ptr1->data <= ptr2->data) {
                
                if(head == NULL) {
                    head = prevNode = ptr1;
                }
                
                else {
                    prevNode->next = ptr1;
                    ptr1->prev = prevNode;
                    prevNode = ptr1;
                }
                
                ptr1 = ptr1->next;
            }
            
            else {
                if(head == NULL) {
                    head = prevNode = ptr2;
                }
                
                else {
                    prevNode->next = ptr2;
                    ptr2->prev = prevNode;
                    prevNode = ptr2;
                }
                
                ptr2 = ptr2->next;
            }
        }
        
        if(ptr1 == NULL) {
            prevNode->next = ptr2;
            ptr2->prev = prevNode;
        }
        
        if(ptr2 == NULL) {
            prevNode->next = ptr1;
            ptr1->prev = prevNode;
        }
        
        return head;
    }
    Node* mergeSort(Node *head) {
        if(head->next == NULL) return head;
        
        Node *slowPtr , *fastPtr;
        slowPtr = head;
        fastPtr = slowPtr->next;
        
        while(fastPtr != NULL and fastPtr->next != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        Node *l2 = slowPtr->next;
        l2->prev = NULL;
        slowPtr->next = NULL;
        
        Node *l1 = mergeSort(head);
        l2 = mergeSort(l2);
        
        return merge(l1 , l2);
    }
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        
        return mergeSort(head);
    }
};