class Solution {
public:
    using ll=long long;
    int mod=1e9+7;
    int m=0;
    map<pair<ll,ll>,ll> mp; 
    ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
    ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
    ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
    int dfs(int i,int p){
        if(mp.find({i,p})!=mp.end()) return mp[{i,p}];
        if(i==m) return 1;
        if(i==0) return mp[{i,p}]=mod_add(mod_mul(6,dfs(i+1,0),mod),mod_mul(6,dfs(i+1,1),mod),mod);
        else{
            if(p==0) return mp[{i,p}]=mod_add(mod_mul(3,dfs(i+1,0),mod),mod_mul(2,dfs(i+1,1),mod),mod);
            else return mp[{i,p}]=mod_add(mod_mul(2,dfs(i+1,0),mod),mod_mul(2,dfs(i+1,1),mod),mod);
        }
    }
    int numOfWays(int n) {
        m=n;
        return dfs(0,-1);
    }
};