// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/reverse-linked-list/description/?envType=daily-question&envId=2024-03-21

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;

        ListNode *prevNode , *currNode , *nextNode;
        prevNode = nextNode = NULL;
        currNode = head;

        while(currNode != NULL) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }

        head = prevNode;

        return head;
    }
};