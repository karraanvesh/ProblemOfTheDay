// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;

        ListNode *slowPtr , *fastPtr;
        slowPtr = head;
        fastPtr = head->next;

        while(fastPtr != NULL and fastPtr->next != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        if(fastPtr != NULL)
        slowPtr = slowPtr->next;

        return slowPtr;
    }
};