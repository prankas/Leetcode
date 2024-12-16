class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto i:times){
            int u=i[0],v=i[1],t=i[2];
            graph[u].push_back({v,t});
        }
        vector<int> min_time(n+1,INT_MAX);
        min_time[0]=1;
        min_time[k]=0;
        set<pair<int,int>> st;
        st.insert({0,k});
        while(!st.empty()){
            auto it=*st.begin();
            st.erase(it);
            for(auto i:graph[it.second]){
                if(min_time[i.first]<=it.first+i.second) continue;
                st.erase({min_time[i.first],i.first});
                min_time[i.first]=it.first+i.second;
                st.insert({it.first+i.second,i.first});
            }
        }
        int ans=*max_element(min_time.begin(),min_time.end());
        return (ans==INT_MAX?-1:ans);
    }
};