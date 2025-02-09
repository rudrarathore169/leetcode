class NumberContainers {
    public:
        map<int,int>m;
        map<int,set<int>>s;
    
        NumberContainers() {
            
        }
        
        void change(int index, int number) {
            if(m.count(index))
            s[m[index]].erase(index);
    
            m[index]=number;
            s[number].insert(index);
        }
        
        int find(int number) {
            if(s.count(number) && !s[number].empty())
            return *s[number].begin();
    
            return -1;
        }
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */