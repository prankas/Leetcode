class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int r=nums[(nums.size()-1)/2];
        for(auto i:nums) ans+=abs(i-r);
        return ans;
    }
};