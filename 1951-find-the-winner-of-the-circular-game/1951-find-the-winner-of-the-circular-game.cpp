class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> visited(n,1);
        int pos=0;
        for(int i=0;i<n-1;i++){
           int sz=n-i;
           int r=k%sz;
           if(r==0) r=sz;
           int cnt=0;
           while(cnt<r || visited[pos]==0){
            if(visited[pos]){
                cnt++;
                if(cnt>=r) break;
            }
            pos++;
            pos%=n;
           }
            visited[pos]=0;
           while(!visited[pos]){
            pos++;
            pos%=n;
           }
        }
        int rem=0;
        for(int i=0;i<n;i++){
            if(visited[i]){
                return i+1;
            }
        }
        return 0;
    }
};