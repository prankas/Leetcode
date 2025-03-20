class Solution {
public:
    int dfs(int i,vector<int> &cmp,int c,vector<vector<pair<int,int>>> &graph,vector<int> &visited){
        if(visited[i]) return ((1<<20)-1);
        visited[i]=1;
        cmp[i]=c;
        int ans=(1<<20)-1;
        for(auto j:graph[i]){
          ans&=j.second;
          if(!visited[j.first])
          ans&=dfs(j.first,cmp,c,graph,visited);
        }
        return ans;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto i:edges){
            graph[i[0]].push_back({i[1],i[2]});
            graph[i[1]].push_back({i[0],i[2]});
        }
        vector<int> cmp(n,0);
        vector<int> visited(n,0);
        map<int,int> mp;
        int c=1;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                mp[c]=dfs(i,cmp,c,graph,visited);
                if(mp[c]==(1<<20)-1) mp[c]=0;
                c++;
            }
        }
        vector<int> ans;
        for(auto i:query){
            if(cmp[i[0]]!=cmp[i[1]]) ans.push_back(-1);
            else ans.push_back(mp[cmp[i[0]]]);
        }
        return ans;
    }
};