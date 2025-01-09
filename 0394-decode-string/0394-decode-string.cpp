class Solution {
public:
    string decodeString(string s) {
        stack<string> prevStr;
        stack<int> repeatCount;
        int n=s.length();
        string curr_str="";
        int num=0;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }else if(s[i]=='['){
                repeatCount.push(num);
                prevStr.push(curr_str);
                num=0;
                curr_str="";
            }else if(s[i]==']'){
                string temp=curr_str;
                curr_str=prevStr.top();
                prevStr.pop();
                int repeat=repeatCount.top();
                repeatCount.pop();
                while(repeat--){
                    curr_str+=temp;
                }
            }else{
                curr_str+=s[i];
            }

        }
        return curr_str;
    }
};