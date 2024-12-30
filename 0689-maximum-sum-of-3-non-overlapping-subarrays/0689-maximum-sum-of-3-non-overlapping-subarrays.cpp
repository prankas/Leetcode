class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> sums(n,0);
        int sum=0;
        for(int i=0;i<k;i++) sum+=nums[i];
        sums[0]=sum;
        for(int i=k;i<n;i++){
            sum-=nums[i-k];
            sum+=nums[i];
            sums[i-k+1]=sum;
        }
        //for(auto )
        vector<vector<int>> dp(n+1,vector<int> (3,0));
        for(int i=n-1;i>=0;i--){
            dp[i][0]=max(dp[i+1][0],sums[i]);
            if(i+k<=n-1) dp[i][1]=max(dp[i+1][1],sums[i]+dp[i+k][0]);
            if(i+2*k<=n-1) dp[i][2]=max(dp[i+1][2],sums[i]+dp[i+k][1]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dp[i][2]==(sums[i]+dp[i+k][1])){
                ans.push_back(i);
                break;
            }
        }
        for(int i=ans[0]+k;i<n;i++){
            if(dp[i][1]==(sums[i]+dp[i+k][0])){
                ans.push_back(i);
                break;
            }
        }
        for(int i=ans[1]+k;i<n;i++){
            if(dp[i][0]==sums[i]){
                ans.push_back(i);
                break;
            }
        }
        return ans; 
    }
};