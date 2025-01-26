class Solution {
public:
    vector<int> cycles;
    map<int,vector<int>> chains;
    void dfs(int curr,int length,map<int,int> &mp,vector<vector<int>> &graph,vector<int> &visited){
       if(mp.find(curr)!=mp.end()){
        cycles.push_back(length-mp[curr]+1);
        return;
       }
       mp[curr]=length+1;
       if(graph[curr].size()==0) return;
       if(visited[curr]) return;
       visited[curr]=1;
       dfs(graph[curr][0],length+1,mp,graph,visited);
    }
    int dfs1(int curr,vector<vector<int>> &rev_graph){
        int m=0;
        for(auto i:rev_graph[curr]){ 
            m=max(m,dfs1(i,rev_graph));
        }
        return m+1;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<vector<int>> graph(n),rev_graph(n);
        vector<int> ind(n,0);
        for(int i=0;i<n;i++){
            if(i!=favorite[favorite[i]]){
            graph[i].push_back(favorite[i]);
            rev_graph[favorite[i]].push_back(i);
            ind[i]++;
            }
        }
        vector<int> visited(n,0);
        int p=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                map<int,int> mp;
                dfs(i,0,mp,graph,visited);
            }
            if(ind[i]==0){
                p+=dfs1(i,rev_graph);
            }
        }
        cycles.push_back(0);
        int ans=*max_element(cycles.begin(),cycles.end());
        ans=max(ans,p);
        return ans;
    }
};