//Queue Reconstruction by Height

class Solution {
public:
    static bool comp(vector<int>v1, vector<int>v2) {
        return  (v1[0] == v2[0]) ? v1[1] < v2[1] : v1[0] > v2[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        
        sort(people.begin(), people.end(), comp);
        
        vector<vector<int>>res;
        for (int i = 0; i < n; i++)
            res.insert(res.begin() + people[i][1], people[i]);
        
        return res;
    }
};
