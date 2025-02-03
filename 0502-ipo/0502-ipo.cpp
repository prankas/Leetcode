class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=capital.size();
        vector<int> c_sort(n);
        iota(c_sort.begin(),c_sort.end(),0);
        sort(c_sort.begin(), c_sort.end(), [&](int i, int j) {
        return capital[i] < capital[j];  
        });
        priority_queue<int> pq;
        int i=0;
        for(int j=0;j<k;j++){
            while(i<n && (capital[c_sort[i]]<=w)){
                pq.push(profits[c_sort[i]]);
                i++;
            } 
            if(!pq.size()) break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};