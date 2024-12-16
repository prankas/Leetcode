class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        set<pair<int,int>> st;
        for(int i=0;i<nums.size();i++) st.insert({nums[i],i});
        while(k){
            pair<int,int> p=*st.begin();
            st.erase(p);
            st.insert({p.first*multiplier,p.second});
            k--;
        }
        for(auto i:st){
            nums[i.second]=i.first;
        }
        return nums;
    }
};