class Solution {
public:
    int maxProfit(int limit, vector<int>& prices) {
        int n=prices.size(),p=2;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(p,vector<int>(limit+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<=limit;k++){
                    if(j%2==0) dp[i][j][k]=max(dp[i+1][0][k],dp[i+1][1][k]-prices[i]);
                    else dp[i][j][k]=max(dp[i+1][0][k-1]+prices[i],dp[i+1][1][k]);
                }
            }
        }
        int m=0;
        for(int i=1;i<=limit;i++){
         m=max(dp[0][0][i],m);
        }
        return m;
    }
};