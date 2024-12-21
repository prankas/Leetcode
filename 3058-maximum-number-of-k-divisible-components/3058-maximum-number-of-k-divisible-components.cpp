class Solution {
public:
    void dfs(int curr,int parent,int &pieces,vector<long long> &summing,vector<int> &values,vector<vector<int>> &tree,int k){
        summing[curr]=values[curr];
        for(auto i:tree[curr]){
            if(i!=parent){
                dfs(i,curr,pieces,summing,values,tree,k);
                summing[curr]+=summing[i];
            }
        }
        if((summing[curr]%k)==0){
            pieces++;
            summing[curr]=0;
        }
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> tree(n);
        for(auto i:edges){
            tree[i[0]].push_back(i[1]);
            tree[i[1]].push_back(i[0]);
        }
        vector<long long> suming(n+1,0);
        int pieces=0;
        dfs(0,-1,pieces,suming,values,tree,k);
        if(suming[0]==0) return pieces;
        return 0;
    }
};