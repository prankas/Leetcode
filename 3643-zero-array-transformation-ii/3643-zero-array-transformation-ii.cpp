class Solution {
public:

    bool checker(int mid,vector<int> &nums,vector<vector<int>> &queries){
        int n=nums.size();
        vector<int> temp(n+1,0);
        for(int i=0;i<mid;i++){
            int left=queries[i][0],right=queries[i][1],val=queries[i][2];
            temp[left]+=val;
            temp[right+1]-=val;
        }
        if(nums[0]>temp[0]) return 0;
        for(int i=1;i<n;i++){
            temp[i]+=temp[i-1];
            if(nums[i]>temp[i]) return 0;
        }
        return 1;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int l=0,r=queries.size(),k=-1;
        while(l<=r){
          int mid=(l+r)>>1;
          if(checker(mid,nums,queries)) k=mid,r=mid-1;
          else l=mid+1;
        }
        return k;
    }
};