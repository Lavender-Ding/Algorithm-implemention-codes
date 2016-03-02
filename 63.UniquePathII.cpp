#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid)
{
    int i,j,rtx,rty,lbx,lby;
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    //if(m==1||n==1) return 1;
    if(obstacleGrid[m-1][n-1]==1) return 0;
    if(m==1)
    {
        for(i=0;i<n;i++)
            if(obstacleGrid[0][i]==1) return 0;
        return 1;
    }
    else if(n==1)
    {
        for(i=0;i<m;i++)
            if(obstacleGrid[i][0]==1) return 0;
        return 1;
    }
    else
    {
        if(obstacleGrid[m-1][n-2]!=1) obstacleGrid[m-1][n-2]=1;
        else obstacleGrid[m-1][n-2]=0;
        if(obstacleGrid[m-2][n-1]!=1) obstacleGrid[m-2][n-1]=1;
        else obstacleGrid[m-2][n-1]=0;
        rtx=m-2;rty=n-1;
        lbx=m-1;lby=n-2;
        for(i=0;i<m+n-3;i++)
        {
            if(rtx-1<0) rty--;
            else rtx--;
            if(lby-1<0) lbx--;
            else lby--;
            //cout<<rtx<<' '<<rty<<' '<<lbx<<' '<<lby<<endl;
            for(j=0;j<lbx-rtx+1;j++)
            {
                if(obstacleGrid[rtx+j][rty-j]==1)
                {
                    obstacleGrid[rtx+j][rty-j]=0;
                    continue;
                }
                if(rtx+j+1>m-1)
                    obstacleGrid[rtx+j][rty-j]=obstacleGrid[rtx+j][rty-j+1];
                else if(rty-j+1>n-1)
                    obstacleGrid[rtx+j][rty-j]=obstacleGrid[rtx+j+1][rty-j];
                else if(rtx+j+1<=m-1&&rty-j+1<=n-1)
                    obstacleGrid[rtx+j][rty-j]=obstacleGrid[rtx+j][rty-j+1]+obstacleGrid[rtx+j+1][rty-j];
            }
        }
    }
    /*for(i=0;i<obstacleGrid.size();i++)
    {
        for(j=0;j<obstacleGrid[i].size();j++) cout<<obstacleGrid[i][j]<<' ';
        cout<<endl;
    }*/
    return obstacleGrid[0][0];
}

int main()
{
    ifstream fin("in.txt");
    vector< vector<int> > grid;
    int tmp;
    char ch;
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
        if(ch=='\n') grid.push_back(nums);
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
    cout<<uniquePathsWithObstacles(grid);
    return 0;
}
