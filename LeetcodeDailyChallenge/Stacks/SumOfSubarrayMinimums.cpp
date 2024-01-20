// Time Complexity  : O(2 * n) ~ O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nextSmaller(n , -1);
        stack<int> st;

        for(int i = 0 ; i < n ; i++) {

            while(!st.empty() and arr[i] < arr[st.top()]) {
                nextSmaller[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        vector<long> sumOfMins(n , 0);
        long result = 0 , mod = 1e9 + 7;

        for(int i = n-1 ; i >= 0 ; i--) {

            if(nextSmaller[i] == -1) {

                int len = n - i;
                long sum = (len * arr[i]);

                result = (result%mod + sum%mod)%mod;

                sumOfMins[i] = sum;
            } else {
                int len = nextSmaller[i] - i;
                long sum = (len * arr[i]);
                long sum2 = sumOfMins[nextSmaller[i]];
                sum = (sum%mod + sum2%mod)%mod;

                result = (result%mod + sum%mod)%mod;

                sumOfMins[i] = sum;
            }
        }

        return result;
    }
};