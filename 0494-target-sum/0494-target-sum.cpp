class Solution {
public:
    using ll=long long;
    int findTargetSumWays(vector<int>& nums, int target) {
        map<int,int> mp;
        int n=nums.size();
        mp[nums[0]]=1;
        mp[-nums[0]]+=1;
        for(int i=1;i<n;i++){
            map<int,int> temp;
            for(auto j:mp){
                temp[j.first+nums[i]]+=j.second;
                temp[j.first-nums[i]]+=j.second;
            }
            mp=temp;
        }
        return mp[target];
    }
};