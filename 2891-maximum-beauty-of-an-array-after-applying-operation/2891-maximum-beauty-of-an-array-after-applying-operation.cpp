class Solution {
public:
    bool chk(int mid,vector<int> &nums,int &k){
         for(int i=nums.size()-mid;i>=0;i--){
            if(nums[i+mid-1]-k<=nums[i]+k) return true;
         }
         return false;
    }

    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=1,r=n,ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(chk(mid,nums,k)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};