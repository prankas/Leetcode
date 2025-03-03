class Solution {
public:
    using ll=long long;
    int maxSum(vector<int>& nums, int k, int m) {
        int n=nums.size();
        vector<ll> prefix(n+1,0ll);
        for(int i=1;i<=n;i++) prefix[i]+=(prefix[i-1]+nums[i-1]);
        vector<vector<ll>> dp(n+1,vector<ll> (k+1,INT_MIN));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=1;j<=k;j++){
            ll offset=INT_MIN;
            for(int i=1;i<=n;i++){
                dp[i][j]=dp[i-1][j];
                if(i-m>=0){
                    offset=max(offset,dp[i-m][j-1]-prefix[i-m]);
                }
                dp[i][j]=max(dp[i][j],prefix[i]+offset);
            }
        }
        return dp[n][k];
    }
};