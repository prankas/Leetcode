class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    
    int findpar(int x){
        if(parent[x]==x || parent[x]==-1) return parent[x];
        return parent[x]=findpar(parent[x]);
    }

    void unionset(int u,int v){
        int pu=findpar(u),pv=findpar(v);
        if(pu==pv) return;
        if(rank[pu]==rank[pv]){
            parent[pv]=pu;
            rank[pu]++;
        } else if(rank[pu]<rank[pv]) parent[pu]=pv;
        else parent[pv]=pu;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> temp(n,vector<int> (n,0));
        parent.resize((n*n)+1,0);
        for(int i=0;i<=(n*n);i++) parent[i]=i;
        rank.resize((n*n)+1,0);
        int p=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j]=p;
                p++;
                if(grid[i][j]==1){
                    if(i-1>=0 && grid[i-1][j]==1) unionset(temp[i][j],temp[i-1][j]);
                    if(j-1>=0 && grid[i][j-1]==1) unionset(temp[i][j],temp[i][j-1]);
                } //else parent[p]=-1;
            }
        }
        int ans=0;
        map<int,int> mp;
        for(int i=0;i<n*n;i++){
            if(parent[i]==-1) continue;
            int par=findpar(i);
            mp[par]++;
            ans=max(mp[par],ans);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                set<int> st;
                if(i-1>=0 && grid[i-1][j]==1) st.insert(findpar(temp[i-1][j]));
                if(j-1>=0 && grid[i][j-1]==1) st.insert(findpar(temp[i][j-1]));
                if(i+1<n && grid[i+1][j]==1) st.insert(findpar(temp[i+1][j]));
                if(j+1<n && grid[i][j+1]==1) st.insert(findpar(temp[i][j+1]));
                int t=0;
                for(auto k:st){
                    //cout<<k<<endl;
                    t+=mp[k];
                }
                ans=max(ans,t+1); 
            }
        }
        return ans;
    }
};