class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0;i<num.length();i++){
            char c=num[i];
            while(!st.empty() && st.top()>c){
                if(k) st.pop(),k--;
                else break;
            }
            st.push(c);
        }
        while(k){
            st.pop();
            k--;
        }
        if(st.empty()) st.push('0');
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.length() && ans[i]=='0') i++;
        if(i>=ans.length()) return ans.substr(0,1);
        return string(ans.begin()+i,ans.end());
    }
};