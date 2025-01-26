class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size(),m=1,ans=0;
        map<int,int> mp;
        vector<int> dp(n,0);
        dp[0]=1,mp[nums[0]]=0;
        for(int i=1;i<n;i++){
            if(mp.find(nums[i])!=mp.end()) dp[i]=dp[mp[nums[i]]];
            if(mp.find(k)!=mp.end()) dp[i]=max(dp[i],dp[mp[k]]);
            dp[i]++;
            mp[nums[i]]=i;
            if(nums[i]==k) m++;
            ans=max({ans,m,dp[i]});
            m=max(m,dp[i]);
        }
        return ans;
    }
};