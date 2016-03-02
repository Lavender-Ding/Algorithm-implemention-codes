#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int DFS(vector<vector<int> >& matrix,vector<vector<int> >& state, int x, int y, int& mlen, int m, int n)
{
    bool flag=false;
    if(state[x][y]>=0) return state[x][y];
    if(x-1>=0&&matrix[x][y]<matrix[x-1][y])
    {
        state[x][y]=max(state[x][y],DFS(matrix,state,x-1,y,mlen,m,n)+1);
        flag=true;
    }
    if(x+1<=m-1&&matrix[x][y]<matrix[x+1][y])
    {
        state[x][y]=max(state[x][y],DFS(matrix,state,x+1,y,mlen,m,n)+1);
        flag=true;
    }
    if(y-1>=0&&matrix[x][y]<matrix[x][y-1])
    {
        state[x][y]=max(state[x][y],DFS(matrix,state,x,y-1,mlen,m,n)+1);
        flag=true;
    }
    if(y+1<=n-1&&matrix[x][y]<matrix[x][y+1])
    {
        state[x][y]=max(state[x][y],DFS(matrix,state,x,y+1,mlen,m,n)+1);
        flag=true;
    }
    if(flag==false) state[x][y]=1;
    mlen=max(mlen,state[x][y]);
    return state[x][y];
}

int longestIncreasingPath(vector<vector<int> >& matrix)
{
    int m=matrix.size();
    if(m==0) return 0;
    int n=matrix[0].size(),mlen=0;
    vector<int> tmp(n,-1);
    vector<vector<int> > state(m,tmp);
    for(int i=0;i<matrix.size();i++)
        for(int j=0;j<matrix[i].size();j++) DFS(matrix,state,i,j,mlen,m,n);
    return mlen;
}

int main()
{
    ifstream fin("in.txt");
    vector< vector<int> > matrix;
    char ch='a';
    int tmp;
    while(1)
    {
        vector<int> nums;
        fin>>tmp;
        nums.push_back(tmp);
        ch=fin.get();
        while(ch!='\n'&&ch!=EOF)
        {
            fin>>tmp;
            nums.push_back(tmp);
            ch=fin.get();
        }
        if(ch=='\n') matrix.push_back(nums);
        if(ch==EOF)
        {
            matrix.push_back(nums);
            break;
        }
    }
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++) cout<<matrix[i][j]<<' ';
        cout<<endl;
    }
    cout<<longestIncreasingPath(matrix);
    return 0;
}
