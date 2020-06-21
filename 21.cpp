//Dungeon Game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int r = d.size();
        if (r == 0) return 0;
        int c = d[0].size();
        if (c == 0) return 0;
        
        vector<vector<int> > dp(r, vector<int>(c, 0));
        
        for (int i=r-1; i>=0; i--) {
            for (int j=c-1; j>=0; j--) {
                if (i == r-1 && j == c-1) {
                    dp[i][j] = min(0, d[i][j]);
                }
                else if (i == r-1) {
                    dp[i][j] = min(0, d[i][j] + dp[i][j+1]);
                }
                else if (j == c-1) {
                    dp[i][j] = min(0, d[i][j] + dp[i+1][j]);
                }
                else {
                    dp[i][j] = min(0, d[i][j] + max(dp[i+1][j], dp[i][j+1]));
                }
            }
        }
        
        /*
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        */
        return abs(dp[0][0]) + 1;
    }
};
