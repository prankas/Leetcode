class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (2,0));
        dp[0][0]=1;
        dp[0][1]=1;
        int m=1;
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0],dp[i][1]=dp[i-1][1];
            if(nums[i]>nums[i-1]) dp[i][0]++,dp[i][1]=1;
            else if(nums[i]<nums[i-1]) dp[i][1]++,dp[i][0]=1;
            else dp[i][0]=dp[i][1]=1;
            m=max({m,dp[i][0],dp[i][1]});
        }
        return m;
    }
};