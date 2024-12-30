class Solution {
public:
    using ll=long long;
    int cnt[1001][1001];
    long long numberOfSubsequences(vector<int>& n) {
        ll res=0;
        memset(cnt,0,sizeof(cnt));
        for(int q=n.size()-5;q>1;q--){
            for(int s=q+4,r=q+2;s<n.size();s++){
                int f=gcd(n[r],n[s]);
                ++cnt[n[r]/f][n[s]/f];
            }
            for(int p=0;p+1<q;p++){
                int f=gcd(n[p],n[q]);
                res += cnt[n[q]/f][n[p]/f];
            }
        }
        return res;
    }
};