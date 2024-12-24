class Solution {
public:
    void dfs1(int curr,int parent,vector<pair<int,int>> &vp,vector<vector<int>> &edges){
        vp[curr].first=1;
        for(auto i:edges[curr]){
            if(i!=parent){
                dfs1(i,curr,vp,edges);
                if(1+vp[i].first>=vp[curr].first){
                    vp[curr].second=vp[curr].first;
                    vp[curr].first=1+vp[i].first;
                } else if(1+vp[i].first>vp[curr].second){
                    vp[curr].second=1+vp[i].first;
                }
            }
        }
    }

    void dfs2(int curr,int parent,vector<pair<int,int>> &vp,vector<vector<int>> &edges){
        for(auto i:edges[curr]){
            if(i!=parent){
            int p=vp[curr].first;
            if((p-vp[i].first)==1) p=vp[curr].second;
            if(p+1>=vp[i].first){
                vp[i].second=vp[i].first;
                vp[i].first=p+1;
            } else if(p+1>vp[i].second) vp[i].second=p+1;
            dfs2(i,curr,vp,edges);
            }
        }
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edge1, vector<vector<int>>& edge2) {
        vector<pair<int,int>> vp1(edge1.size()+1,{0,0}),vp2(edge2.size()+1,{0,0});
        vector<vector<int>> edges1(edge1.size()+1),edges2(edge2.size()+1);
        for(auto i:edge1){
            edges1[i[0]].push_back(i[1]);
            edges1[i[1]].push_back(i[0]);
        }
        for(auto i:edge2){
            edges2[i[0]].push_back(i[1]);
            edges2[i[1]].push_back(i[0]);
        }
        dfs1(0,-1,vp1,edges1);
        dfs2(0,-1,vp1,edges1);
        dfs1(0,-1,vp2,edges2);
        dfs2(0,-1,vp2,edges2);
        int d1=0,d2=0,m1=INT_MAX,m2=INT_MAX;
        for(auto i:vp1){
            if(i.second>0) d1=max(d1,i.first+i.second-2);
            else d1=max(d1,i.first-1);
            m1=min(m1,i.first-1);
        }
        for(auto i:vp2){
            if(i.second>0) d2=max(d2,i.first+i.second-2);
            else d2=max(d2,i.first-1);
            m2=min(m2,i.first-1);
        }
        if(m1==INT_MAX) m1=0;
        if(m2==INT_MAX) m2=0;
        return max({d1,d2,m1+m2+1});
    }
};