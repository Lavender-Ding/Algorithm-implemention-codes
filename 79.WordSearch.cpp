#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool flag=false;

void adjacent(int x,int y,int head,string word,vector<vector<char> >& board)
{
    if(head==word.size()-1)
    {
        flag=true;
        return;
    }
    if(x-1>=0&&board[x-1][y]==word[head+1]&&flag==false)
    {
        board[x-1][y]+=26;
        adjacent(x-1,y,head+1,word,board);
        board[x-1][y]-=26;
    }
    if(x+1<board.size()&&board[x+1][y]==word[head+1]&&flag==false)
    {
        board[x+1][y]+=26;
        adjacent(x+1,y,head+1,word,board);
        board[x+1][y]-=26;
    }
    if(y-1>=0&&board[x][y-1]==word[head+1]&&flag==false)
    {
        board[x][y-1]+=26;
        adjacent(x,y-1,head+1,word,board);
        board[x][y-1]-=26;
    }
    if(y+1<board[x].size()&&board[x][y+1]==word[head+1]&&flag==false)
    {
        board[x][y+1]+=26;
        adjacent(x,y+1,head+1,word,board);
        board[x][y+1]-=26;
    }
}

bool exist(vector<vector<char> >& board, string word)
{
    if(board.size()==0||word.size()==0) return false;
    bool isgrid=true;
    int head=0;
    flag=false;
    //vector<vector<int> > use;
    //for(int i=0;i<board.size())
    vector<int> line;
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            if(flag!=true&&board[i][j]==word[0])
            {
                board[i][j]+=26;
                adjacent(i,j,head,word,board);
                board[i][j]-=26;
            }
        }
    }
    return flag;
}

int main()
{
    ifstream fin("in.txt");
    string word;
    vector<vector<char> > board;
    vector<char> line;
    fin>>word;
    char c=fin.get();
    while(!fin.eof())
    {
        c=fin.get();
        if(c=='\n')
        {
            board.push_back(line);
            line.clear();
            continue;
        }
        line.push_back(c);
    }
    board.push_back(line);
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++) cout<<board[i][j];
        cout<<endl;
    }
    for(int i=0;i<word.size();i++) cout<<word[i];
    cout<<endl;
    cout<<exist(board,word);
    return 0;
}
