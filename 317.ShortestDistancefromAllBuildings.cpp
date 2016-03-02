#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

int shortestDistance(vector<vector<int> >& grid)
{
    if(grid.size()==0) return -1;
    int i,j,m=grid.size(),n=grid[0].size();
    vector<pair<int,int> > build_pos;
    bool falg=false;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            if(grid[i][j]==1) build_pos.push_back(pair<int,int>(i,j));
            if(grid[i][j]==2) grid[i][j]=-1;
        }
    if(build_pos.size()==0) return -1;
    pair<int,int> tmp_pos;
    vector<int> row(n,0);
    vector<vector<int> > state(m,row);
    int buildings=build_pos.size();
    for(i=0;i<buildings;i++)
    {
        vector<pair<int,int> > points;
        vector<int> tmp(n,1);
        vector<vector<int> > tmp_dis(m,tmp);
        points.push_back(build_pos[i]);
        int left=0,right=points.size();
        while(left<right)
        {
            for(j=left;j<right;j++)
            {
                tmp_pos=points[j];
                int x=tmp_pos.first,y=tmp_pos.second,dis=tmp_dis[x][y];
                if(x-1>=0&&abs(grid[x-1][y])!=1&&state[x-1][y]==i)
                {
                    tmp_dis[x-1][y]=dis+1;
                    grid[x-1][y]+=tmp_dis[x-1][y];
                    points.push_back(pair<int,int>(x-1,y));
                    state[x-1][y]++;
                }
                if(x+1<m&&abs(grid[x+1][y])!=1&&state[x+1][y]==i)
                {
                    tmp_dis[x+1][y]=dis+1;
                    grid[x+1][y]+=tmp_dis[x+1][y];
                    points.push_back(pair<int,int>(x+1,y));
                    state[x+1][y]++;
                }
                if(y-1>=0&&abs(grid[x][y-1])!=1&&state[x][y-1]==i)
                {
                    tmp_dis[x][y-1]=dis+1;
                    grid[x][y-1]+=tmp_dis[x][y-1];
                    points.push_back(pair<int,int>(x,y-1));
                    state[x][y-1]++;
                }
                if(y+1<n&&abs(grid[x][y+1])!=1&&state[x][y+1]==i)
                {
                    tmp_dis[x][y+1]=dis+1;
                    grid[x][y+1]+=tmp_dis[x][y+1];
                    points.push_back(pair<int,int>(x,y+1));
                    state[x][y+1]++;
                }
            }
            left=right;
            right=points.size();
        }
    }
    int min_num=INT_MAX;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(state[i][j]==buildings&&grid[i][j]<min_num) min_num=grid[i][j];
    if(min_num==INT_MAX) return -1;
    return min_num-buildings;
}

int main()
{
    ifstream fin("in.txt");
    vector<vector<int> > grid;
    int tmp;
    char ch;
    vector<int> nums;
    while(1)
    {
        fin>>tmp;
        nums.push_back(tmp);
        ch=fin.get();
        if(ch=='\n')
        {
            grid.push_back(nums);
            nums.clear();
        }
        if(ch==EOF)
        {
            grid.push_back(nums);
            break;
        }
    }
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++) cout<<grid[i][j]<<' ';
        cout<<endl;
    }
    cout<<shortestDistance(grid);
    return 0;
}
