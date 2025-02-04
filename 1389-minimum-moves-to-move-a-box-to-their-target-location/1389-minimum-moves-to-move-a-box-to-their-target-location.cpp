class Solution {
public:
    using State=tuple<int,int,int,int,int>;
    int minPushBox(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int bx,by,sx,sy,tx,ty;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='B') bx=i,by=j;
                else if(grid[i][j]=='T') tx=i,ty=j;
                else if(grid[i][j]=='S') sx=i,sy=j;
            }
        }
        queue<State> q;
        bool visited[21][21][21][21]={};
        q.push({bx,by,sx,sy,0});
        visited[bx][by][sx][sy]=1;
        int dirs[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        auto canReach = [&](int bx,int by,int ex,int ey,int sx,int sy)->bool{
           vector<vector<bool>> seen(n,vector<bool> (m,false));
           queue<pair<int,int>> qq;
           qq.push({sx,sy});
           seen[sx][sy]=1;
           while(!qq.empty()){
            auto [x,y]=qq.front();
            qq.pop();
            if(x==ex && y==ey) return 1;
            for(auto &d:dirs){
                int nx=x+d[0],ny=y+d[1];
                if(nx==bx && ny==by) continue;
                if(nx>=0 && ny>=0 && nx<n && ny<m && !seen[nx][ny] && grid[nx][ny]!='#'){
                    seen[nx][ny]=1;
                    qq.push({nx,ny});
                }
            }
           }
           return false;
        };
        while(!q.empty()){
            auto [cbx,cby,cpx,cpy,pushes]=q.front();
            q.pop();
            if(cbx==tx && cby==ty) return pushes;
            for(auto &d:dirs){
               int nbx=cbx+d[0],nby=cby+d[1];
               int reqx=cbx-d[0],reqy=cby-d[1];
               if(nbx<0 || nby<0 || nbx>=n || nby>=m || grid[nbx][nby]=='#') continue;
               if(reqx<0 || reqy<0 || reqx>=n || reqy>=m || grid[reqx][reqy]=='#') continue;
               if(!canReach(cbx,cby,reqx,reqy,cpx,cpy)) continue;
               if(!visited[nbx][nby][cbx][cby]){
                visited[nbx][nby][cbx][cby]=1;
                q.push({nbx,nby,cbx,cby,pushes+1});
               }
            }
        }
        return -1;
    }
};