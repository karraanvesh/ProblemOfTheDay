// Time  Complexity : O(max(n , m))
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/minimum-common-value/?envType=daily-question&envId=2024-03-09

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // non-decreasing order --> increasing with duplicates 

        int n = nums1.size();
        int m = nums2.size();

        int i , j;
        i = j = 0;
        int minElement = -1;

        while(i < n and j < m) {

            if(nums1[i] < nums2[j]) {
                i++;
            }

            else if(nums2[j] < nums1[i]) {
                j++;
            }

            else {
                minElement = nums1[i];
                break;
            }
        }

        return minElement;
    }
};