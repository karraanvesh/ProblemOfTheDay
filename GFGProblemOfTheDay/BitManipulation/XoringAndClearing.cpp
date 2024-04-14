// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/xoring-and-clearing/1

class Solution {
  public:
    void printArr(int n, int arr[]) {
        for(int i = 0 ; i < n ; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void setToZero(int n, int arr[]) {
        for(int i = 0 ; i < n ; i++) {
            arr[i] = 0;
        }
    }

    void xor1ToN(int n, int arr[]) {
        for(int i = 0 ; i < n ; i++) {
            arr[i] = i ^ arr[i];
        }
    }
};