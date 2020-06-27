//perfect squares
class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;dp[1]=1;
        for(int i=2 ; i<=n ; i++)
            for(int j=1 ; j<=sqrt(i) ; j++)
                if(i>=j*j)
                {
                    int x=min(dp[i],dp[i-j*j]);
                    if(x==INT_MAX) dp[i]=INT_MAX;
                    else dp[i]=min(dp[i],x+1);
                }
        return dp[n];
    }
};
