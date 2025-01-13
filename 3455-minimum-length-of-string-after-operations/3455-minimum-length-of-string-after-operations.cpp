class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        map<char,int> mp;
        for(int i=0;i<n;i++) mp[s[i]]++;
        int ans=0;
        for(auto i:mp){
            if(i.second<3) ans+=i.second;
            else{
                if(i.second%2) ans++;
                else ans+=2;
            }
        }
        return ans;
    }
};