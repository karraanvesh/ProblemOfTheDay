// Time  Complexity : O(2 * n) ~ O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/merge-in-between-linked-lists/description/?envType=daily-question&envId=2024-03-20

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *ptr = list1;
        int ct = -1;

        ListNode *temp1 , *temp2 , *prevNode;
        prevNode = temp1 = temp2 = NULL;

        while(ptr != NULL) {
            ct++;

            if(ct == a) {
                temp1 = prevNode;
            }

            if(ct == b+1) {
                temp2 = ptr;
            }

            prevNode = ptr;
            ptr = ptr->next;
        }

        temp1->next = list2;
        ListNode *ptr1 = list2;
        prevNode = NULL;

        while(ptr1 != NULL) {
            prevNode = ptr1;
            ptr1 = ptr1->next;
        }

        prevNode->next = temp2;

        return list1;
    }
};