// Time  Complexity : O(n * logn)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/?envType=daily-question&envId=2024-03-18

class Solution {
    private :
    static bool compare(vector<int> &v1 , vector<int> &v2) {
        return v1[1] < v2[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int noOfPoints = points.size();

        sort(points.begin() , points.end() , compare);
        int end = points[0][1];
        int minArrows = 1;

        for(int i = 1 ; i < noOfPoints ; i++) {
            int currStart = points[i][0];
            int currEnd = points[i][1];

            if(!(end >= currStart and end <= currEnd)) {
                minArrows++;
                end = currEnd;
            }
        }

        return minArrows;
    }
};