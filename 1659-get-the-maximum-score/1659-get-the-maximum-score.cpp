class Solution {
public:
    using ll=long long;
    ll md=1e9+7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        map<ll,ll> mp;
        int i=nums1.size()-1,j=nums2.size()-1;
        vector<ll> dp1(nums1.size()+1,0),dp2(nums2.size()+1,0);
        while(i>=0 && j>=0){
            if(nums1[i]==nums2[j]){
                if(dp2[j+1]>dp1[i+1]){
                    dp2[j]=nums2[j]+dp2[j+1];
                    mp[nums2[j]]=dp2[j];
                    j--;
                }
                else{
                    dp1[i]=nums1[i]+dp1[i+1];
                    mp[nums1[i]]=dp1[i];
                    i--;
                }
            }
            else if(nums1[i]>nums2[j]){
                dp1[i]=max(nums1[i]+dp1[i+1],mp[nums1[i]]);
                mp[nums1[i]]=dp1[i];
                i--;
            } else{
                dp2[j]=max(nums2[j]+dp2[j+1],mp[nums2[j]]);
                mp[nums2[j]]=dp2[j];
                j--;
            }
        }
        while(j>=0){
            dp2[j]=max(nums2[j]+dp2[j+1],mp[nums2[j]]);
            mp[nums2[j]]=dp2[j];
            j--;
        }
        while(i>=0){
            dp1[i]=max(nums1[i]+dp1[i+1],mp[nums1[i]]);
            mp[nums1[i]]=dp1[i];
            i--;
        }
        return max(dp1[0],dp2[0])%md;
    }
};