// Time  Complexity : O(n * n)
// Space Complexity : O(n * n)

// Problem Link : https://leetcode.com/problems/k-th-smallest-prime-fraction/description/?envType=daily-question&envId=2024-05-10

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double ,pair<int , int>>> vect;

        int n = arr.size();

        for(int i = 0 ; i < n ; i++) {

            for(int j = i + 1 ; j < n ; j++) {
                double ans = ((double) arr[i] / arr[j]);

                vect.push_back({ans , {i , j}});
            }
        }

        sort(vect.begin() , vect.end());

        vector<int> result;
        int ind1 = vect[k - 1].second.first , ind2 = vect[k - 1].second.second;

        result.push_back(arr[ind1]);
        result.push_back(arr[ind2]);

        return result;
    }
};