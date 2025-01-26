class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size(),m=1,ans=0;
        map<int,int> mp;
        vector<int> dp(n,0);
        dp[0]=1;
        mp[nums[0]]=0;
        for(int i=1;i<n;i++){
            int p=0;
            if(mp.find(nums[i])!=mp.end()) p=max(p,dp[mp[nums[i]]]);
            if(mp.find(k)!=mp.end()) p=max(p,dp[mp[k]]);
            dp[i]=p+1;
            mp[nums[i]]=i;
            if(nums[i]==k) m++;
            ans=max({ans,m,dp[i]});
            m=max(m,dp[i]);
        }
        return ans;
    }
};