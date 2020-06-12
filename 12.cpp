//Insert Delete GetRandom O(1)
class RandomizedSet {
public:
    unordered_set<int>con;
    vector<int>v;
    RandomizedSet() {
        con.clear(),v.clear();
    }
    bool insert(int val) {
        if(!con.empty()){
           auto it = find(begin(con),end(con),val);
            if(it==con.end()){
                con.insert(val);
                v.push_back(val);
            }else{
              return false;  
            }
        }else{
                con.insert(val);
                v.push_back(val);
            }
        return true;
    }
    bool remove(int val) {
        if(con.empty())return false;
        auto it = find(begin(con),end(con),val);
        if(it==end(con))return false;
        con.erase(it);
        auto it1 = find(begin(v),end(v),val);
        v.erase(it1);
        return true;
    }
    int getRandom() {
        return v[rand()%v.size()];
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
