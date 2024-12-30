class Solution {
public:
    using ll=long long;
    int numWays(vector<string>& words, string target) {
        int MOD=1e9+7;
        ll n=words.size(),m=target.size(),len=words[0].length();
        vector<map<char,ll>> mp(len);
        for(ll i=0;i<len;i++){
            for(ll j=0;j<n;j++){
                mp[i][words[j][i]]++;
            }
        }
        vector<vector<ll>> dp(m+1,vector<ll> (len+1,1));
        // dp[i][j]=mp[target[i]][j]*dp[i+1][j+1]
        // dp[i][j]+=dp[i][j+1];
        for(ll i=m-1;i>=0;i--){
            dp[i][len]=0;
            for(ll j=len-1;j>=0;j--){
                dp[i][j]=(mp[j][target[i]]*dp[i+1][j+1])%MOD;
                dp[i][j]=(dp[i][j]+dp[i][j+1])%MOD;
            }
        }
        return dp[0][0];
    }
};