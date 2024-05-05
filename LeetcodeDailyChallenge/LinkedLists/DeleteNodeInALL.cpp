// Time  Complexity : O(1)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/delete-node-in-a-linked-list/description/?envType=daily-question&envId=2024-05-05

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;

        return ;
    }
};