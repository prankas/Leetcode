class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.length();
        int i=0,j=0,cnt=0,cnt1=0;
        vector<int> let(n,0);
        vector<int> lett(n,0);
        for(int i=0;i<n;i++){
            if(start[i]!='_') cnt1++;
            if(target[i]!='_') cnt++;
            lett[i]=cnt,let[i]=cnt1;
        }
        while(i<n && j<n){
            if(start[i]=='_') i++;
            if(target[j]=='_') j++;
            if(start[i]!='_' && target[j]!='_'){
                if(start[i]!=target[j]) return 0;
                if(start[i]=='L'){
                    if(((i+1)-let[i])<((j+1)-lett[j])) return 0;
                } else if(start[i]=='R'){
                    int a=(n-i)-(let[n-1]-let[i]);
                    int b=(n-j)-(lett[n-1]-lett[j]);
                    if(a<b) return 0;
                }
                i++,j++;
            }
        }
        while(i<n && start[i]=='_') i++;
        while(j<n && target[j]=='_') j++;
        if(i<n || j<n) return 0;
        return 1;
    }
};