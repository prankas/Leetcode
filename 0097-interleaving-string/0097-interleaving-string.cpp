class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
       int n=s1.length(),m=s2.length();
       if((n+m)!=s3.length()) return 0;
       if(n==0 && m==0) return true;
       vector<vector<int>> dp(n+1,vector<int> (m+1,0));
       dp[0][0]=1;
       for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if((i+j)==0) continue;
            int p=0;
            if((i-1)>=0) p=dp[i-1][j]&(s1[i-1]==s3[i+j-1]);
            if((j-1)>=0) p=max(p,dp[i][j-1]&(s2[j-1]==s3[i+j-1]));
            dp[i][j]=p;
        }
       }
       return dp[n][m];
    }
};