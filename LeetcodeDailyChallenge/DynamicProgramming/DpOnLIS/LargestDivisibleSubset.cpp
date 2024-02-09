// Time  Complexity : O(n * n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/largest-divisible-subset/description/?envType=daily-question&envId=2024-02-09

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());
        vector<int> dp(n , 1) , parent(n , 0);

        for(int i = 0 ; i < n ; i++) {
            parent[i] = i;
        }

        int maxSubset = 1 , position = 0;

        for(int i = 1 ; i < n ; i++) {
            int maxi = 1 , pos = i;
            for(int j = i-1 ; j >= 0 ; j--) {
                int currNum = nums[i];
                int prevNum = nums[j];

                if(currNum%prevNum == 0) {
                    int x = 1 + dp[j];

                    if(x > maxi) {
                        maxi = x;
                        pos = j;
                    }
                }
            }

            dp[i] = maxi;
            parent[i] = pos;

            if(maxi > maxSubset) {
                maxSubset = maxi;
                position = i;
            }
        }
        
        vector<int> result;

        while(parent[position] != position) {
            result.push_back(nums[position]);
            position = parent[position];
        }

        result.push_back(nums[position]);

        reverse(result.begin() , result.end());

        return result;
    }
};