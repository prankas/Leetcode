class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=0;
        pair<int,int> a={values[0],0};
        for(int i=1;i<values.size();i++){
            ans=max(ans,a.first+values[i]-(i-a.second));
            if(a.first-(i-a.second)<values[i]) a={values[i],i};
        }
        return ans;
    }
};