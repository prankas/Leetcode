class Solution {
public:
    string simplify(string ans,int &i,string &s){
        while(i>=0 && s[i]!='['){
        if(s[i]==']') {i--; ans+=simplify("",i,s); continue;}
        ans+=s[i];
        i--;
        }
        i--;
        string nums="";
        while(i>=0 && s[i]>='0' && s[i]<='9'){
            nums+=s[i];
            i--;
        }
        reverse(nums.begin(),nums.end());
        int num=0;
        for(auto i:nums){num*=10; num+=i-'0';}
        string ret="";
        while(num) ret.append(ans),num--;
        return ret;
    }
    string decodeString(string s) {
        stack<string> s1;
        int n=s.length(),i=n-1;
        string ans="";
        while(i>=0){
          if(s[i]==']'){
            i--;
            ans+=simplify("",i,s);
          } else ans+=s[i],i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};