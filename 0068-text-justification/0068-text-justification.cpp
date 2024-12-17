class Solution {
public:
vector<string> fullJustify(vector<string> &word, int maxWidth) {
    // Write your code here
    vector<string> ans;
    int i=0,n=word.size(),start=0,count=-1;
    while(i<n){
        if((count+word[i].length()+1)>maxWidth){
            string to_insert="";
            int spaces=maxWidth-count,word_count=max(1,i-start-1);
            int even=spaces/word_count,odd=spaces%word_count;
            for (int j = start; j < i-1; j++) {
              to_insert += word[j];
              to_insert += " ";
              for (int k = 0; k < even; k++)
                to_insert += " ";
              if (odd)
                to_insert += " ", odd--;
            }
            to_insert+=word[i-1];
            while(to_insert.length()<maxWidth) to_insert+=" ";
            ans.push_back(to_insert);
            start=i;
            count=-1;
        }
        count+=(word[i].length()+1);
        i++;
    }
    string to_insert="";
    for(int i=start;i<word.size()-1;i++){
        to_insert+=word[i];
        to_insert+=" ";
    }
    to_insert+=word[n-1];
    while(to_insert.length()<maxWidth) to_insert+=" ";
    if(to_insert.length()) ans.push_back(to_insert);
    return ans;
}
};
