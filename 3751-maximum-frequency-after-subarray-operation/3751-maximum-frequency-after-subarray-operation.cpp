class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
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
        }
        int m=0,ans=0;
        for(int i=n-1;i>=0;i--){
            ans=max(ans,m+dp[i]);
            if(nums[i]==k) m++;
        }
        return ans;
    }
};