class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if(n%2) return 0;
        vector<int> dp(n+1,0),dp1(n+1,0);
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0'){
              dp[i]=max(0,dp[i+1]-1);
            } else{
                if(s[i]=='(')  dp[i]=max(0,dp[i+1]-1);
                else dp[i]=dp[i+1]+1;
            }
        }
        for(int j=1;j<=n;j++){
         int i=j-1;
            if(locked[i]=='0'){
              dp1[j]=max(0,dp1[j-1]-1);
            } else{
                if(s[i]==')')  dp1[j]=max(0,dp1[i]-1);
                else dp1[j]=dp1[i]+1;
            }
        }
        return (dp[0]==0 && dp1[n]==0);
    }
};