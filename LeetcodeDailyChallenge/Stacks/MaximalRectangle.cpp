// Time  Complexity : O(n * m) + O(n * (2 * m)) ~ O(n * m)
// Space Complexity : O(n * m)

// Problem Link : https://leetcode.com/problems/maximal-rectangle/?envType=daily-question&envId=2024-04-13

class Solution {
    private :
    int largestHistogram(vector<int> &arr , int n) {
        vector<int> leftSmaller(n , -1) , rightSmaller(n , -1);

        stack<int> st1 , st2;

        for(int i = 0 ; i < n ; i++) {

            while(!st1.empty() and arr[i] < arr[st1.top()]) {
                rightSmaller[st1.top()] = i;
                st1.pop();
            }

            st1.push(i);
        }

        for(int i = n - 1 ; i >= 0 ; i--) {

            while(!st2.empty() and arr[i] < arr[st2.top()]) {
                leftSmaller[st2.top()] = i;
                st2.pop();
            }

            st2.push(i);
        }

        int maxArea = 0;
        for(int i = 0 ; i < n ; i++) {

            if(arr[i] == 0)
            continue;

            int end1 , end2;

            end1 = (leftSmaller[i] == -1) ? 0 : (leftSmaller[i] + 1);
            end2 = (rightSmaller[i] == -1) ? (n - 1) : (rightSmaller[i] - 1);

            int breath = (end2 - end1) + 1;
            int length = arr[i];

            int area = (length * breath);

            maxArea = max(maxArea , area);
        }

        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> grid(n , vector<int>(m , 0));

        for(int j = 0 ; j < m ; j++) {

            if(matrix[0][j] == '1')
            grid[0][j] = 1;
        }

        for(int i = 1 ; i < n ; i++) {

            for(int j = 0 ; j < m ; j++) {

                if(matrix[i][j] == '1')
                grid[i][j] = grid[i-1][j] + 1;

                else
                grid[i][j] = 0;
            }
        }

        int result = 0;
        for(int i = 0 ; i < n ; i++) {
            int maxi = largestHistogram(grid[i] , m);
            result = max(result , maxi);
        }

        return result;
    }
};