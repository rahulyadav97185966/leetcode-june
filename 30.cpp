//Word Search II
class Solution {
public:
    struct Trie
    {
      Trie *next[26];
      bool fn;
      int ind;
      Trie()
        {
            for(int i=0;i<26;i++)this->next[i]=NULL;
            this->fn=false;
            this->ind=-1;
        }
    };
    vector<string>ans;
    int row=0,col=0;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    void add(Trie *root,string x,int pos)
    {
        for(int i=0;i<x.size();i++)
        {
            int ind=x[i]-'a';
            if(root->next[ind]==NULL)root->next[ind]=new Trie();
            root=root->next[ind];
        }
        root->fn=true;
        root->ind=pos;
    }
    void dfs(Trie *root,vector<string>&words,vector<vector<char>>& board,int i,int j)
    {
        if(i<0 || j<0 || i>=row || j>=col)
        {
            if(root->fn==true && root->ind!=-1){
                ans.push_back(words[root->ind]);
                root->ind=-1;
            }
            return;
        }
        if(root->fn==true && root->ind!=-1){
            ans.push_back(words[root->ind]);
            root->ind=-1;
        }
        if(board[i][j]!='.' and !root->next[board[i][j]-'a'])return;
        if(board[i][j]=='.')return;
        char ch=board[i][j];
        board[i][j]='.';
        for(int k=0;k<4;k++)
        {
            int fx=i+dx[k],fy=j+dy[k];
            dfs(root->next[ch-'a'],words,board,fx,fy);
        }
        board[i][j]=ch;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *root=new Trie();
        for(int i=0;i<words.size();i++)add(root,words[i],i);
        row=board.size();
        if(row==0)return ans;
        col=board[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++){
                int ind=board[i][j]-'a';
                if(root->next[ind])dfs(root,words,board,i,j);
            }
        }
        return ans;
        
    }
};
