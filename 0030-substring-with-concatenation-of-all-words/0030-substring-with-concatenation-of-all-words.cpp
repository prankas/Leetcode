class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
       int n=s.length(),m=words.size();
       vector<int> ans;
       map<string,int> s1;
       for(auto i:words) s1[i]++;
       for(int i=0;i<words[0].length();i++){
        deque<string> dq;
        map<string,int> st;
        for(int j=i;j<n;j+=words[0].length()){
            string h=s.substr(j,words[0].length());
            if(s1.find(h)==s1.end()){
                dq.clear();
                st.clear();
                continue;
            }
            else if(st[h]>=s1[h]){
                while(dq.front()!=h){
                    st[dq.front()]--;
                    dq.pop_front();
                }
                st[h]--;
                dq.pop_front();
            }
            dq.push_back(h);
            st[h]++;
            if(dq.size()==words.size()) ans.push_back(j-(m-1)*words[0].length());
        }
       }
       return ans;
    }
};