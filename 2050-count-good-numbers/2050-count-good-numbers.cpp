class Solution {
public:
    using ll=long long;
    ll power(ll x,ll y){
        ll mod=1e9+7;
        ll ret = 1, mul = x;
            while (y > 0) {
                if (y % 2 == 1) {
                    ret = (ret * mul) % mod;
                }
                mul = (mul * mul) % mod;
                y /= 2;
            }
            return ret;
    }
    int countGoodNumbers(long long n) {
       int k=1e9+7;
       ll even=(n+1)/2,odd=n/2;
       return ((power(5,even)%k)*(power(4,odd)%k)%k);
    }
};