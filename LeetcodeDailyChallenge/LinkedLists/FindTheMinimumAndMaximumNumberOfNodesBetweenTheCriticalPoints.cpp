/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/?envType=daily-question&envId=2024-07-05

class Solution {
    private :
    bool isMin(ListNode *currNode , ListNode *prevNode , ListNode *nextNode) {

        return ((currNode->val < prevNode->val) and (currNode->val < nextNode->val));
    }

    bool isMax(ListNode *currNode , ListNode *prevNode , ListNode *nextNode) {

        return ((currNode->val > prevNode->val) and (currNode->val > nextNode->val));
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> result(2 , -1);

        if(head->next->next == NULL) return result;

        int ct = 1;
        ListNode *currNode = head , *prevNode , *nextNode;

        prevNode = currNode;
        currNode = currNode->next;
        nextNode = NULL;

        int minInd , maxInd;
        minInd = maxInd = -1;

        vector<int> arr;
        int firstCP , lastCP , prevCP;
        prevCP = firstCP = lastCP = -1;

        int maxDist = INT_MIN;
        int minDist = INT_MAX;
        bool b;


        while(currNode->next->next != NULL) {
            ct++;

            nextNode = currNode->next;
            b = false;

            if(isMin(currNode , prevNode , nextNode) ) {
                b = true;
            }

            if(isMax(currNode , prevNode , nextNode)) {
                b = true;
            }

            if(b) {

                if(firstCP == -1) {
                    firstCP = ct;
                }

                if(prevCP != -1) {
                    minDist = min(minDist , ct - prevCP);
                }

                prevCP = lastCP = ct;
                lastCP = ct;
            }

            prevNode = currNode;
            currNode = currNode->next;
        }

        nextNode = currNode->next;
        ct++;

        b = false;

        if(isMin(currNode , prevNode , nextNode)) {
            b = true;
        }

        if(isMax(currNode , prevNode , nextNode)) {
            b = true;
        }

        if(b) 
        {
            if(prevCP != -1) {
                minDist = min(minDist , ct - prevCP);
            }

            lastCP = ct;
        }

        if(firstCP == -1 or firstCP == lastCP) return result;

        maxDist = max(maxDist , lastCP - firstCP);

        result[0] = minDist;
        result[1] = maxDist;

        return result;
    }
};