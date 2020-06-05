//Random Pick with Weight

class Solution {
private:
    vector<int> sums;
    unordered_map<int,int> m;
public:
    Solution(vector<int>& w) {
        srand(time(NULL));
        int sum = 0;
        for (int i = 0; i < w.size(); i ++) {
            sum += w[i];
            sums.push_back(sum);
            m[sum] = i;
        }
    }
    
    int pickIndex() {
        return m[*upper_bound(sums.begin(), sums.end(), rand() % sums.back())];
    }
};
