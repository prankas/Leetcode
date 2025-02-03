class Solution {
public:
    bool check(vector<int>& nums) {
        int j=nums.size(); bool f=0;
        for(int i=1;i<nums.size();i++)
        if(nums[i]<nums[i-1]){j=i; if(nums[j]>nums[0]) return 0; break;}
        for(int i=j+1;i<nums.size();i++){
        if((nums[i]<nums[i-1])||(nums[i]>nums[0])){f=1; break;}
        }
        return !f;
    }
};