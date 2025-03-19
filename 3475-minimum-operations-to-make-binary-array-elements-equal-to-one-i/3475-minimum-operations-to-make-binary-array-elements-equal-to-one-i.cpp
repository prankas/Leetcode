class Solution {
public:
    int minOperations(vector<int>& nums) {
     int c=0,n=nums.size();
     for(int i=0;i<nums.size()-2;i++){
       if(nums[i]==0){
        c++;
        nums[i]=1;
        nums[i+1]=(nums[i+1]+1)%2;
        nums[i+2]=(nums[i+2]+1)%2;
       }
     }
     if(nums[n-1]+nums[n-2]<2) return -1;
     return c;
    }
};