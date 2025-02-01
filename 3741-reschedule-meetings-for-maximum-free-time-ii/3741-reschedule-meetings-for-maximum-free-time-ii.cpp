class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> free,occ;
        set<pair<int,int>> st;
        map<int,int> chk;
        for(int i=0;i<startTime.size();i++) st.insert({startTime[i],endTime[i]});
        free.push_back(st.begin()->first);
        chk[free[0]]++;
        auto it=*st.begin();
        occ.push_back(it.second-it.first);
        st.erase(it);
        while(st.size()){
            auto p=*st.begin();
            occ.push_back(p.second-p.first);
            st.erase(p);
            free.push_back(p.first-it.second);
            chk[p.first-it.second]++;
            it=p;
        }
        free.push_back(eventTime-it.second);
        chk[eventTime-it.second]++;
        int ans=*max_element(free.begin(),free.end());
        for(int i=0;i<occ.size();i++){
            int cur=free[i],next=free[i+1];
            chk[cur]--;
            if(chk[cur]==0) chk.erase(cur);
            chk[next]--;
            if(chk[next]==0) chk.erase(next);
            if(chk.rbegin()->first>=occ[i]) ans=max(ans,cur+next+occ[i]);
            chk[next]++;
            ans=max(ans,cur+next);
            chk[cur]++;
        }
        return ans;
    }
};