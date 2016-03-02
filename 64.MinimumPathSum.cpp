#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int minPathSum(vector< vector<int> >& grid)
{
    int i,j,rtx,rty,lbx,lby;
    int m=grid.size();
    int n=grid[0].size();
    rtx=m-1;rty=n-1;
    lbx=m-1;lby=n-1;
    for(i=0;i<m+n-2;i++)
    {
        if(rtx-1<0) rty--;
        else rtx--;
        if(lby-1<0) lbx--;
        else lby--;
        for(j=0;j<lbx-rtx+1;j++)
        {
            if(rtx+j+1>m-1)
                grid[rtx+j][rty-j]=grid[rtx+j][rty-j]+grid[rtx+j][rty-j+1];
            else if(rty-j+1>n-1)
                grid[rtx+j][rty-j]=grid[rtx+j][rty-j]+grid[rtx+j+1][rty-j];
            else if(rtx+j+1<=m-1&&rty-j+1<=n-1)
            {
                if(grid[rtx+j][rty-j+1]<=grid[rtx+j+1][rty-j])
                    grid[rtx+j][rty-j]=grid[rtx+j][rty-j]+grid[rtx+j][rty-j+1];
                else
                    grid[rtx+j][rty-j]=grid[rtx+j][rty-j]+grid[rtx+j+1][rty-j];
            }
        }
    }
    /*for(i=0;i<grid.size();i++)
    {
        for(j=0;j<grid[i].size();j++) cout<<grid[i][j]<<' ';
        cout<<endl;
    }*/
    return grid[0][0];
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
    cout<<minPathSum(grid);
    return 0;
}
