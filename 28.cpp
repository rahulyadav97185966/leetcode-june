
//Reconstruct Itinerary
class Solution {
public:
    vector<int> used;
    vector<int> zero;
    int flag = 0;
    vector<string> ans;
    void func(vector<vector<string>>& tickets, vector<string>& ret, string now){
        if(flag == 1)return;
        if(used == zero){
            ans = ret;
            flag = 1;
            return;
        }
        for(int i=0; i<tickets.size(); i++){
            if(tickets[i][0] == now && !used[i]){
                used[i] = 1;
                ret.push_back(tickets[i][1]);
                func(tickets, ret, tickets[i][1]);
                ret.pop_back();
                used[i] = 0;
            }
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(),tickets.end());
        used.resize(tickets.size(),0);
        zero.resize(tickets.size(),1);
        vector<string> ret;
        ret.push_back("JFK");
        func(tickets,ret,"JFK");
        return ans;
    }
};
