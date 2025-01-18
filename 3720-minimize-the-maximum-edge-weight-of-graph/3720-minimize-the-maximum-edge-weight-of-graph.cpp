class Solution {
public:
    set<int> st;
    void dfs(int curr,int wt,int &mid,vector<int> &visited,vector<vector<pair<int,int>>> &complement){
       if(wt>mid || visited[curr]>0) return;
       visited[curr]=1;
       for(auto i:complement[curr]){
        int p=i.second;
        if(curr==0 && visited[p]==0) visited[0]++;
        dfs(i.second,i.first,mid,visited,complement);
       }
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>> complement(n);
        for(int i=0;i<edges.size();i++){
            if(edges[i][1]==0) st.insert(edges[i][0]);
            complement[edges[i][1]].push_back({edges[i][2],edges[i][0]});
        }
        int l=0,r=1e9,ans=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            vector<int> visited(n,0);
            dfs(0,0,mid,visited,complement);
            int f=1;
            for(int i=1;i<n;i++) if(visited[i]==0) f=0;
            if(f) ans=mid,r=mid-1;
            else l=mid+1;
        }
        if(ans==INT_MAX) ans=-1;
        return ans;
    }
};