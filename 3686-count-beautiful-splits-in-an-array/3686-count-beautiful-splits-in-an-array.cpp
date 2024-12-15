class Solution {
public:
    vector<int> z_array(vector<int>& arr) {
        int n = arr.size();
            vector<int> z(n, 0);

            int l = 0, r = 0;
            for (int i = 1; i < n; ++i) 
            {
                if (i <= r) z[i] = min(r - i + 1, z[i - l]);
                while (i + z[i] < n && arr[z[i]] == arr[i + z[i]]) ++z[i];
                if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
            }

            return z;
    }
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> z_num(n);
        for (int i = 0; i < n; i++) {
            vector<int> suf(nums.begin()+i,nums.end());
            z_num[i] = z_array(suf);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // Subarrays:
                // [0..i - 1] -> nums1
                // [i...j - 1] -> nums2
                // [j...n - 1] -> nums3

                if (z_num[0][i] >= i && (j - i) >= i) ans++;
                else if (z_num[i][j - i] >= (j - i) && (n - j) >= (j - i)) ans++;
            }
        }
        return ans;
    }
};