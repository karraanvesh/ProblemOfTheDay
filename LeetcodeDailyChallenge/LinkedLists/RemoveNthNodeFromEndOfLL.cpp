// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/?envType=daily-question&envId=2024-03-03

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL) return NULL;

        int ct = n - 1;
        ListNode *slowPtr , *fastPtr;
        slowPtr = fastPtr = head;

        while(ct ) {
            fastPtr = fastPtr->next;
            ct--;
        }

        ListNode *prevNode = NULL;

        while(fastPtr->next != NULL) {
            prevNode = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        
        if(prevNode == NULL) {
            ListNode *ptr = head;
            head = head->next;
            delete ptr;
            return head;
        }

        prevNode->next = slowPtr->next;
        delete slowPtr;

        return head;
    }
};