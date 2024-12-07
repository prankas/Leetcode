class Solution {
public:
    bool checker(int mid,vector<int> &nums,int &maxOperations){
        int n=nums.size(),op=0;
        for(int i=0;i<n;i++){
            if(nums[i]>mid){
                op+=((nums[i]/mid)-1);
                if(nums[i]%mid) op++;
            }
        }
        return op<=maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1,r=*max_element(nums.begin(),nums.end());
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            if(checker(mid,nums,maxOperations)) r=mid-1,ans=mid;
            else l=mid+1;
        }
        return ans;
    }
};