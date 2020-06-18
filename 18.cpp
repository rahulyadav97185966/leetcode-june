//H-Index II

class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        if(n==0) return 0;
        int l=1,h=n,mid;
        while(l<=h){
            mid = l + (h-l)/2;
            if(c[n-mid] == mid) return mid; 
            else if(c[n-mid] > mid) l = mid+1;
            else h = mid-1;
        }
        return h && (c[n-h] >= h) ? h : 0;
    }
};
