class Solution {
public:
    using ll=long long;
    int countGoodStrings(int low, int high, int zero, int one) {
        int MOD=1e9+7,ans=0;
        vector<int> dp(high+1,0);
        dp[0]=1;
        for(int i=1;i<=high;i++){
            int a=(i-zero>=0)?dp[i-zero]:0;
            a%=MOD;
            int b=(i-one>=0)?dp[i-one]:0;
            b%=MOD;
            a=(a+b)%MOD;
            dp[i]=(dp[i]+a)%MOD;
            if(i>=low)
            ans=(ans+dp[i])%MOD;
        }
        return ans;
    }
};