class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int n = s.length(), i = s.length() - 1, num = 0;
        string ans = "";
        st.push(ans);
        while (i >= 0) {
            if (s[i] >= '0' && s[i] <= '9') {
                string nums = "";
                while (i >= 0 && s[i] >= '0' && s[i] <= '9') {
                    nums += s[i];
                    i--;
                }
                reverse(nums.begin(), nums.end());
                int num = 0;
                for (auto i : nums) {
                    num *= 10;
                    num += i - '0';
                }
                string p = st.top();
                st.pop();
                string q = st.top();
                st.pop();
                while (num)
                    q.append(p), num--;
                st.push(q);
            } else if (s[i] == ']') {
                i--;
                string p = "";
                while (i >= 0) {
                    if (s[i] == '[' || s[i] == ']')
                        break;
                    p += s[i];
                    i--;
                }
                st.push(p);
            } else if (s[i] == '[') {
                i--;
            } else {
                string q = st.top();
                st.pop();
                q += s[i];
                st.push(q);
                i--;
            }
        }
        ans = st.top();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};