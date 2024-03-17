// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/insert-interval/?envType=daily-question&envId=2024-03-17

class Solution {
    private :
    static bool compare(vector<int> &v1 , vector<int> &v2) {

        if(v1[0] < v2[0]) return true;

        return false;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int noOfIntervals = intervals.size();

        vector<vector<int>> allIntervals = intervals;
        allIntervals.push_back(newInterval);

        sort(allIntervals.begin() , allIntervals.end() , compare);
        int start , end;
        start = allIntervals[0][0];
        end = allIntervals[0][1];

        vector<vector<int>> result;

        for(int i = 1 ; i < allIntervals.size() ; i++) {
            int currStart = allIntervals[i][0];
            int currEnd = allIntervals[i][1];

            if(currStart >= start and currStart <= end) {
                end = max(end , currEnd);
            }

            else {
                vector<int> mergedInterval;
                mergedInterval.push_back(start);
                mergedInterval.push_back(end);

                result.push_back(mergedInterval);

                start = currStart;
                end = currEnd;
            }
        }

        vector<int> mergedInterval;
        mergedInterval.push_back(start);
        mergedInterval.push_back(end);

        result.push_back(mergedInterval);

        return result;
    }
};