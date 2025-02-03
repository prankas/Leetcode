struct State {
    int bx, by, px, py, pushes;
};
 
class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        pair<int,int> target, box, player;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(grid[i][j]=='T') target = {i,j};
                else if(grid[i][j]=='B') box = {i,j};
                else if(grid[i][j]=='S') player = {i,j};
            }
        }
        // Heuristic: Manhattan distance from box to target.
        auto heuristic = [&](int bx, int by) {
            return abs(bx - target.first) + abs(by - target.second);
        };
        
        // Comparator for A* using f = pushes + h.
        auto cmp = [&](const State &a, const State &b) {
            return a.pushes + heuristic(a.bx, a.by) > b.pushes + heuristic(b.bx, b.by);
        };
        priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);
        
        // visited[bx][by][px][py]
        bool visited[21][21][21][21] = {};
        pq.push({box.first, box.second, player.first, player.second, 0});
        visited[box.first][box.second][player.first][player.second] = true;
 
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
 
        auto isValid = [&](int x, int y) {
            return x>=0 && x<m && y>=0 && y<n && grid[x][y] != '#';
        };
 
        auto canReach = [&](int sx, int sy, int tx, int ty, int bx, int by) -> bool {
            vector<vector<bool>> seen(m, vector<bool>(n,false));
            queue<pair<int,int>> q;
            q.push({sx,sy});
            seen[sx][sy] = true;
            while(!q.empty()){
                auto [x,y] = q.front(); q.pop();
                if(x==tx && y==ty) return true;
                for(auto &d : dirs){
                    int nx = x+d[0], ny = y+d[1];
                    if(isValid(nx,ny) && !seen[nx][ny] && !(nx==bx && ny==by)){
                        seen[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
            return false;
        };
 
        while(!pq.empty()){
            auto [cbx, cby, cpx, cpy, pushes] = pq.top();
            pq.pop();
            if(cbx==target.first && cby==target.second)
                return pushes;
 
            for(auto &d : dirs){
                int nbx = cbx + d[0], nby = cby + d[1];   // new box position if pushed
                int reqX = cbx - d[0], reqY = cby - d[1];   // player must be here to push
                if(!isValid(nbx, nby) || !isValid(reqX, reqY)) continue;
                if(!canReach(cpx, cpy, reqX, reqY, cbx, cby)) continue;
                if(!visited[nbx][nby][cbx][cby]){
                    visited[nbx][nby][cbx][cby] = true;
                    pq.push({nbx, nby, cbx, cby, pushes+1});
                }
            }
        }
 
        return -1;
    }
};