// Time  Complexity : O(2 * nlogn) ~ O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/?envType=daily-question&envId=2024-03-12

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummyHead = new ListNode(0);
        int sum = 0;
        map<int , ListNode*> mp;
        mp.insert({sum , dummyHead});
        ListNode *ptr = head , *newHead , *prevNode;
        newHead = NULL;
        prevNode = dummyHead;
        
        while(ptr != NULL) {
            int ele = ptr->val;
            sum += ele;
            
            if(ele == 0) {
                ptr = ptr->next;
                continue;
            }
            
            if(mp.find(sum) != mp.end())   {
                ListNode *node = mp[sum];
                ListNode *nextNode = node->next;
                int temp = sum + nextNode->val;
                
                while(nextNode != NULL){
                    mp.erase(temp);
                    nextNode = nextNode->next;
                    if(nextNode != NULL)
                    temp += nextNode->val;    
                }
                
                node->next = NULL;
                prevNode = node;
                
                if(sum == 0) 
                    newHead = NULL;
            }
            
            else {
                ListNode *newNode = new ListNode(ele);
                
                if(newHead == NULL)           {
                    dummyHead->next = newNode;
                    newHead = prevNode = newNode;
                }
                
                else {
                    prevNode->next = newNode;
                    prevNode = newNode;
                }
                
                mp.insert({sum , newNode});
            } 
            
            ptr = ptr->next;
        }
        
        return newHead;
    }
};