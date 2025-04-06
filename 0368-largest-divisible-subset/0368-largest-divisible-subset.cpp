class Solution {
public:
    using ll=long long;
    vector<int> largestDivisibleSubset(vector<int>& v) {
        ll n=v.size();
        sort(v.begin(),v.end());
        vector<vector<int>> dp(n);
        dp[n-1].push_back(v[n-1]);
        ll m=1;
        for(ll i=n-2;i>=0;i--){
            dp[i].push_back(v[i]);
            for(ll j=i+1;j<n;j++){
                if(v[j]%v[i]==0){
                    if(dp[j].size()+1>dp[i].size()){
                        dp[i]=dp[j];
                        dp[i].push_back(v[i]);
                    }
                }
            }
            m=max(m,(ll)dp[i].size());
        }
        for(auto i:dp){
            if(i.size()==m) return i;
        }
        return {};
    }
};