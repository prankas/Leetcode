class Solution {
public:
    string getHint(string secret, string guess) {
        int a=0,b=0;
        map<char,int> gues,secre;
        for(int i=0;i<max(secret.length(),guess.length());i++){
            if(i>=secret.length()) gues[guess[i]]++;
            else if(i>=guess.length()) secre[secret[i]]++;
            else{
                if(guess[i]==secret[i]) a++;
                else gues[guess[i]]++,secre[secret[i]]++;
            }
        }
        for(auto i:secre){
            b+=min(i.second,gues[i.first]);
        }
        string ans="";
        string temp="";
        while(a>0){
            int p=a%10;
            temp+=('0'+p);
            a/=10;
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        temp.clear();
        if(ans.length()==0) ans+='0';
        ans+='A';
        int j=ans.length();
        while(b>0){
            int p=b%10;
            temp+=('0'+p);
            b/=10;
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        if(ans.length()==j) ans+='0';
        ans+='B';
        return ans;
    }
};