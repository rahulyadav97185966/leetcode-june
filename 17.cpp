//Surrounded Regions

class Solution {
public:
    void dfs(vector<vector<char>>& b,int i,int j)
    {
        if(b[i][j]=='O')
        {
            b[i][j]='Y';
            if(i<b.size()-1) dfs(b,i+1,j);
            if(j<b[0].size()-1) dfs(b,i,j+1);
            if(i>1) dfs(b,i-1,j);
            if(j>1) dfs(b,i,j-1);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.size()==0) return;
        int n=board.size(),m=board[0].size();
        for(int i=0 ; i<n ; i++){
            dfs(board,i,0);
            if(m>1) dfs(board,i,m-1);
        }
        for(int j=0 ; j<m ; j++){
            dfs(board,0,j);
            if(n>1) dfs(board,n-1,j);
        }
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++)
            {
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='Y') board[i][j]='O';
            }
    }
};
