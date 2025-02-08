class NumberContainers {
public:
    map<int,set<int>> mp;
    map<int,int> p;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(p.find(index)!=p.end()) mp[p[index]].erase(index);
        p[index]=number;
        mp[number].insert(index);
    }
    
    int find(int number) {
        if(mp[number].size()==0) return -1;
        return *mp[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */