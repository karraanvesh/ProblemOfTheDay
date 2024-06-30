// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/identical-linked-lists/1

// Function to check whether two linked lists are identical or not.
bool areIdentical(struct Node *head1, struct Node *head2) {
    Node *ptr1 , *ptr2;
    
    ptr1 = head1;
    ptr2 = head2;
    bool result = false;
    
    while(ptr1 != NULL and ptr2 != NULL) {
        
        if(ptr1->data != ptr2->data)
        return result;
        
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    if((ptr1 and !ptr2) or (!ptr1 and ptr2))
    return result;
    
    return !result;
}