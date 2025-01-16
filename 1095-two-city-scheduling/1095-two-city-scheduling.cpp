class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<tuple<int,int,int>> v;
        for(int i=0;i<costs.size();i++){
            v.push_back({costs[i][1]-costs[i][0],costs[i][0],costs[i][1]});
        }
        sort(v.begin(),v.end(),greater<tuple<int,int,int>>());
        int ans=0,cnt=0;
        for(auto i:v){
          if(cnt<costs.size()/2) ans+=get<1>(i);
          else ans+=get<2>(i);
          cnt++;
        }
        return ans;
    }
};