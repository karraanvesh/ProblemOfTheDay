// Time  Complexity : O(n * 2 * 3) ~ O(n)
// Space Complexity : O(2 * (2 * 3)) ~ O(1)

class Solution {
public:
    long checkRecord(int n) {

        vector<vector<long>> prev(3 , vector<long>(4 , 1));
        long mod = 1e9 + 7;

        for(int j = 0 ; j <= 3 ; j++) {
            prev[2][j] = 0;
        }

        for(int i = 0 ; i <= 2 ; i++) {
            prev[i][3] = 0;
        }

        for(int temp = 1 ; temp <= n ; temp++) {

            vector<vector<long>> curr(3 , vector<long>(4 , 0));

            for(int absentCt = 0 ; absentCt <= 2 ; absentCt++) {

                for(int lateCt = 0 ; lateCt <= 3 ; lateCt++) {

                    if(absentCt >= 2 or lateCt >= 3) {
                        continue;
                    }

                    curr[absentCt][lateCt] = (prev[absentCt][0]%mod + prev[absentCt + 1][0]%mod + prev[absentCt][lateCt + 1]%mod)%mod;
                }
            }

            prev = curr;
        }

        return prev[0][0];
    }
};