class Solution {
public:
    string repeatLimitedString(string s, int maxWidth) {
        map<char,int> mp;
        set<char> st;
        for(auto i:s) mp[i]++,st.insert(i);
        string ans="";
        char curr,prev;
        if(st.size()==1){
            curr=*st.rbegin();
            for(int i=1;i<=min(mp[curr],maxWidth);i++) ans+=curr;
            return ans;
        }
        curr=*st.rbegin();
        st.erase(curr);
        prev=*st.rbegin();
        st.erase(prev);
        while(!st.empty()){
            if(mp[curr]==0){
                curr=prev;
                prev=*st.rbegin();
                st.erase(prev);
            } else if(ans.length()>0){
                mp[prev]--;
                ans+=prev;
            }
            int p=mp[curr];
            for(int i=1;i<=min(p,maxWidth);i++) ans+=curr,mp[curr]--;
            if(mp[prev]==0 && st.size()>0){
                prev=*st.rbegin();
                st.erase(prev);
            }
        }
        while(mp[prev]>0 && mp[curr]>0){
            if(ans.length()){
                ans+=prev;
                mp[prev]--;
            }
            int p=mp[curr];
            for(int i=1;i<=min(p,maxWidth);i++) ans+=curr,mp[curr]--;
        }
        if(mp[curr]==0){
            curr=prev;
            int p=mp[curr];
            for(int i=1;i<=min(p,maxWidth);i++) ans+=curr,mp[curr]--;
        } 
        return ans;
    }
};