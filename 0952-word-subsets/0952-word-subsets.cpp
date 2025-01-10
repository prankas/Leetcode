class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int> mp;
        for(auto i:words2){
            map<char,int> mp1;
            for(auto j:i) mp1[j]++;
            for(auto k:mp1) mp[k.first]=max(mp[k.first],k.second);
        }
        vector<string> ans;
        for(auto i:words1){
            map<char,int> mp1;
            for(auto j:i) mp1[j]++;
            int f=1;
            for(auto j:mp){
                if(mp1[j.first]<j.second){
                    f=0;
                    break;
                }
            }
            if(f) ans.push_back(i);
        }
        return ans;
    }
};