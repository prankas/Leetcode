class Solution {
public:
    using ll=long long;
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> dp(2001,0);
        dp[nums[0]+1000]=1;
        dp[-nums[0]+1000]+=1;
        for(int i=1;i<nums.size();i++){
            vector<int> temp(2001,0);
            for(int j=0;j<=2000;j++){
                if(j+nums[i]<=2000) temp[j+nums[i]]+=dp[j];
                if(j-nums[i]>=0) temp[j-nums[i]]+=dp[j];
            }
            dp=temp;
        }
        return dp[target+1000];
    }
};