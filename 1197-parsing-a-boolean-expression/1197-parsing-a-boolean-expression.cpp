class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        int n=expression.length();
        for(int i=0;i<n;i++){
            if(expression[i]==',') continue;
            else if(expression[i]==')'){
                stack<int> st1;
                char c=st.top();
                st.pop();
                while(c!='('){
                    if(c=='f') st1.push(0);
                    else st1.push(1);
                    c=st.top();
                    st.pop();
                }
                c=st.top();
                st.pop();
                if(c=='&'){
                    int ans=st1.top();
                    st1.pop();
                    while(!st1.empty()) ans&=st1.top(),st1.pop();
                    if(ans==1) st.push('t');
                    else st.push('f');
                } else if(c=='|'){
                    int ans=st1.top();
                    st1.pop();
                    while(!st1.empty()) ans|=st1.top(),st1.pop();
                    if(ans==1) st.push('t');
                    else st.push('f');
                } else{
                    if(st1.top()==1) st.push('f');
                    else st.push('t');
                }
            }
            else{
                st.push(expression[i]);
            }
        }
        return st.top()=='f'?0:1;
    }
};