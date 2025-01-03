class Solution {
public:
    using ll=long long;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        map<string,ll> mp;
        int n=original.size();
        for(int i=0;i<n;i++){
            string temp="";
            temp+=original[i];
            temp+=changed[i];
            if(mp.find(temp)!=mp.end())
            mp[temp]=min(mp[temp],(ll)cost[i]);
            else mp[temp]=cost[i];
        }
        set<pair<ll,string>> st;
        for(auto i:mp){
            st.insert({i.second,i.first});
        }
        map<string,ll> record;
        while(!st.empty()){
            auto i=*st.begin();
            st.erase(i);
            ll c=i.first;
            string str=i.second;
            //if(str=="dc") cout<<str;
            if(record.find(str)!=record.end() && record[str]<=c) continue;
            record[str]=c;
            map<string,ll> temp;
            for(auto j:record){
                if(j.first[1]==str[0]){
                    string p="";
                    p+=j.first[0];
                    p+=str[1];
                    if(record.find(p)!=record.end())
                    temp[p]=min((ll)record[p],c+j.second);
                    else
                    temp[p]=c+j.second;
                } if(j.first[0]==str[1]){
                    string p="";
                    p+=str[0];
                    p+=j.first[1];
                    if(record.find(p)!=record.end())
                    temp[p]=min((ll)record[p],c+j.second);
                    else temp[p]=c+j.second;
                }
            }
            for(auto j:temp){
                st.insert({j.second,j.first});
            }
        }
        //for(auto i:record) cout<<i.first<<" "<<i.second<<endl;
        ll ans=0;
        for(int i=0;i<source.length();i++){
            if(source[i]!=target[i]){
                string p="";
                p+=source[i];
                p+=target[i];
                if(record.find(p)==record.end()){
                    cout<<p<<endl;
                    return -1;
                }
                ans+=record[p];
            }
        }
        return ans;
    }
};