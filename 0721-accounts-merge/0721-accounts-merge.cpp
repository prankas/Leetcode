class Solution {
public:
    vector<int> parent,rank;
    int findpar(int x){
        if(parent[x]==x) return x;
        return parent[x]=findpar(parent[x]);
    }
    void unionset(int x,int z){
        int px=findpar(x),pz=findpar(z);
        if(rank[px]<rank[pz]) parent[px]=pz;
        else if(rank[pz]<rank[px]) parent[pz]=px;
        else{
            parent[pz]=px;
            rank[px]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        parent.resize(accounts.size());
        rank.resize(accounts.size(),0);
        for(int i=0;i<accounts.size();i++) parent[i]=i;
        map<string,vector<int>> mp;
        int p=0;
        for(auto i:accounts){
            for(int j=1;j<i.size();j++){
                mp[i[j]].push_back(p);
            }
            p++;
        }
        p=0;
        for(auto q:mp){
            vector<int> i=q.second;
            int n=i.size();
            for(int j=1;j<n;j++) unionset(i[j],i[j-1]);
        }
        vector<set<string>> st(accounts.size()+1);
        for(int i=0;i<parent.size();i++){
            if(parent[i]!=i) findpar(i);
            else p++;
        }
        vector<vector<string>> ans(p);
        p=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i){
                ans[p].push_back(accounts[i][0]);
                p++;
                for(int j=1;j<accounts[i].size();j++) st[i].insert(accounts[i][j]);
            } else{
                int par=findpar(i);
                for(int j=1;j<accounts[i].size();j++) st[par].insert(accounts[i][j]);
            }
        }
        p=0;
        for(int i=0;i<st.size();i++){
            if(st[i].size()==0) continue;
            for(auto j:st[i]) ans[p].push_back(j);
            p++;
        }
        return ans;
    }
};