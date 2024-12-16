class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> edge(n,vector<int> (n,1e9));
        for(auto i:edges){
          edge[i[0]][i[1]]=min(edge[i[0]][i[1]],i[2]);
          edge[i[1]][i[0]]=min(edge[i[1]][i[0]],i[2]);
        }
        for(int i=0;i<n;i++) edge[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
                }
            }
        }
        pair<int,int> p={0,1e9};
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=0;j<n;j++){
                if(edge[i][j]<=distanceThreshold) s++;
            }
            if(p.second>=s) p={i,s}; 
        }
        return p.first;
    }
};