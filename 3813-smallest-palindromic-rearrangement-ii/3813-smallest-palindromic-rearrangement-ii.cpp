class Solution {
public:
    using ll=long long;
    const ll maxk=1000001;
    ll multinomial(map<char,int> &cnt){
     int total=0;
     for(auto i:cnt){
        total+=i.second;
     }
     long res=1;
     for(int i=0;i<26;i++){
        int p=cnt['a'+i];
        res=res*binom(total,p);
        if(res>=maxk) return maxk;
        total-=p;
     }
     return res;
    }

    ll binom(int n,int k){
        if(k>n) return 0;
        if(k>n-k) k=n-k;
        ll res=1;
        int cnt=0;
        for(int i=1;i<=k;i++){
            res=(res*(n-i+1))/i;
            cnt++;
            if(res>=maxk) return maxk;
        }
        return res;
    }

    string smallestPalindrome(string s, int k) {
        int n=s.length();
        map<char,int> mp;
        for(auto i:s) mp[i]++;
        char mid;
        for(auto i:mp){
            if(i.second%2){
                mid=i.first;
                break;
            }
        }
        map<char,int> half;
        int halfcnt=0;
        for(auto i:mp){
            half[i.first]=i.second/2;
            halfcnt+=i.second/2;
        }
        string firsthalf="";
        for(int i=0;i<halfcnt;i++){
            for(int c=0;c<26;c++){
                if(half['a'+c]>0){
                    half['a'+c]--;
                    ll perms=multinomial(half);
                    if(perms>=k){
                        firsthalf+=('a'+c);
                        break;
                    } else{
                        k-=perms;
                        half['a'+c]++;
                    }
                }
                //mmkrn
            }
        }
        string sec=firsthalf;
        reverse(sec.begin(),sec.end());
        string ans="";
        if(mid>='a' && mid<='z')
        ans= (firsthalf+mid+sec);
        else
        ans= (firsthalf+sec);
        if(ans.length()!=n) return "";
        return ans;
    }

};