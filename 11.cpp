//Sort Colors

class Solution {
public:
    void swap(int *xp, int *yp)  
    {  
        int temp = *xp;  
        *xp = *yp;  
        *yp = temp;  
    }
    void sortColors(vector<int>& nums) {
    int i, j;  
    for (i = 0; i < nums.size(); i++)      
        for (j = 0; j < nums.size()-i-1; j++)  
            if (nums[j] > nums[j+1])  
                swap(&nums[j], &nums[j+1]); 
        
    }
};
