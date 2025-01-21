class Solution {
public:
    using ll=long long;
    int mod=1e9+7;
    ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
    ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
    ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
    int numOfWays(int n) {
        vector<vector<int>> dp(n,vector<int> (2,1));
        dp[0][0]=6,dp[0][1]=6;
        for(int i=1;i<n;i++){
            dp[i][0]=mod_add(mod_mul(dp[i-1][0],3,mod),mod_mul(dp[i-1][1],2,mod),mod);
            dp[i][1]=mod_add(mod_mul(dp[i-1][0],2,mod),mod_mul(dp[i-1][1],2,mod),mod);
        }
        return mod_add(dp[n-1][0],dp[n-1][1],mod);
    }
};