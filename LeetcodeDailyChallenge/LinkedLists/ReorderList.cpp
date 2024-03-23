// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/reorder-list/description/?envType=daily-question&envId=2024-03-23

class Solution {
    private :
    ListNode* reverseList(ListNode *head) {
        if(head == NULL or head->next == NULL)
        return head;

        ListNode *prevNode , *currNode , *nextNode;
        prevNode = nextNode = NULL;
        currNode = head;

        while(currNode != NULL) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }

        return prevNode;
    }
public:
    void reorderList(ListNode* head) {
        if(head == NULL or head->next == NULL)
        return ;

        ListNode *slowPtr , *fastPtr;
        slowPtr = head;
        fastPtr = head->next;

        while(fastPtr != NULL and fastPtr->next != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        ListNode *head2 = slowPtr->next;
        slowPtr->next = NULL;

        head2 = reverseList(head2);

        ListNode *ptr1 , *ptr2;
        ptr1 = head;
        ptr2 = head2;

        while(ptr1 != NULL and ptr2 != NULL) {
            ListNode *nextNode1 , *nextNode2;
            nextNode1 = ptr1->next;
            nextNode2 = ptr2->next;
            ptr1->next = ptr2;
            ptr2->next = nextNode1;
            ptr1 = nextNode1;
            ptr2 = nextNode2;
        }

        return ;
    }
};