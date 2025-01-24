class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> transposeGraph(n);
        for(int i=0;i<n;i++){
            for(auto j:graph[i]) transposeGraph[j].push_back(i);
        }
        vector<int> indegree(n,0),ans;
        for(int i=0;i<n;i++){
            for(auto j:transposeGraph[i]) indegree[j]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(!indegree[i]) q.push(i);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto i:transposeGraph[top]){
                indegree[i]--;
                if(!indegree[i]) q.push(i);
            }
            ans.push_back(top);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};