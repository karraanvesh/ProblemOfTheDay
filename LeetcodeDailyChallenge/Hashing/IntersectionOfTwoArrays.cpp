// Time  Complexity : O(nlogn + mlogm)
// Space Complexity : O(n + m)

// Problem Link : https://leetcode.com/problems/intersection-of-two-arrays/?envType=daily-question&envId=2024-03-10

class Solution {
    private :
    void findUnique(vector<int> &arr , int n , set<int> &st) {

        for(int i = 0 ; i < n ; i++) {
            st.insert(arr[i]);
        }

        return ;
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        set<int> st1 , st2;

        findUnique(nums1 , n , st1);
        findUnique(nums2 , m , st2);

        set<int> :: iterator itr;
        vector<int> result;

        for(itr = st2.begin() ; itr != st2.end() ; itr++) {
            int ele = *itr;

            if(st1.count(ele)) {
                result.push_back(ele);
            }
        }

        return result;
    }
};