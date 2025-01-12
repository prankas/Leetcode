class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if(n%2) return 0;
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0'){
              dp[i][0]=max(0,dp[i+1][0]-1);
              dp[i][1]=dp[i+1][1]-1;
            } else{
                if(s[i]=='(')  dp[i][0]=max(0,dp[i+1][0]-1),dp[i][1]=dp[i+1][1]+1;
                else dp[i][0]=dp[i+1][0]+1,dp[i][1],dp[i][1]=dp[i+1][1]-1;
                if(dp[i][1]>0) return 0;    
            }
        }
        return (dp[0][0]==0);
    }
};