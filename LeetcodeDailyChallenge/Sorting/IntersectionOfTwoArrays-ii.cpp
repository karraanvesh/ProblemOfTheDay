// Time Complexity: O(n*logn + m*logm + max(n , m))
// Space Complexity : O(min(n , m))

// Problem Link : https://leetcode.com/problems/intersection-of-two-arrays-ii/description/?envType=daily-question&envId=2024-07-02

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin() , nums1.end());
        
        sort(nums2.begin() , nums2.end());
        
        int n = nums1.size();
        int m = nums2.size();
        
        int i , j;
        i = j = 0;
        vector<int> result;
        
        while(i < n and j < m) {
            
            while(i < n and nums1[i] < nums2[j]) {
                i++;
            }
            
            while(j < m and nums2[j] < nums1[i]) {
                j++;
            }
            
            while(i < n and j < m and nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        
        return result;
    }
};