// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2024-03-06

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL or head->next == NULL)
            return false;
        
        ListNode *slowPtr , *fastPtr;
        slowPtr = head;
        fastPtr = slowPtr->next;
        
        while(fastPtr != NULL and fastPtr->next != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            
            if(slowPtr == fastPtr)
                return true;
        }
        
        return false;
    }
};