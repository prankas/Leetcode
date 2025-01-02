class Solution {
public:
    int longesPalindromicSubsequence(string s1){
        if(s1.length()<=1) return s1.length();
        string s2=s1;
        reverse(s2.begin(),s2.end());
        int n=s1.length();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        dp[n-1][n-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                if(s1[i]==s2[j]) dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
    int maxProduct(string s) {
        int n=s.length();
        int ans=0;
        for(int i=(1<<n)-1;i>0;i--){
            string s1="",s2="";
            for(int j=0;j<n;j++){
                if((1<<j)&i) s1+=s[j];
                else s2+=s[j];
            }
            int a=longesPalindromicSubsequence(s1);
            int b=longesPalindromicSubsequence(s2);
            ans=max(ans,a*b);
        }
        return ans;
    }
};