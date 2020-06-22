//Single Number II

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        if(nums.size()==1){
            return nums[0];
        }
        else{
            unordered_map<int, int> umap;
            for(int i=0;i<nums.size();i++){
                int key = nums[i];
                if (umap.find(key) == umap.end()) {
                    umap[key]++;
                }   
                else{
                    umap[key] = 0;
                }
            }
            for(auto& i: umap) 
            { 
                if(i.second == 1){
                    return i.first;
                }
            }   
        }
        return 0;
    }
};
