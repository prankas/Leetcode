class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        map<int,vector<int>> mp;
        for(auto i:envelopes){
            mp[i[0]].push_back(i[1]);
        }
        int ans=1;
        for(auto &i:mp) sort(i.second.begin(),i.second.end(),greater<int>());
        map<int,int> mp1;
        for(auto i:mp){
            for(auto j:i.second){
                if(mp1.size()>0){
                auto it=mp1.lower_bound(j);
                if(it==mp1.begin()) mp1[j]=1;
                else{
                    it--;
                    mp1[j]=max(mp1[j],it->second+1);
                    it=mp1.lower_bound(j+1);
                    while(it!=mp1.end()){
                    if(it->second<=mp1[j]) mp1.erase(it->first);
                    else break;
                    it=mp1.lower_bound(j+1);
                    }
                }
                } else mp1[j]=1;
            }
        }
        ans=mp1.rbegin()->second;
        return ans;
    }
};