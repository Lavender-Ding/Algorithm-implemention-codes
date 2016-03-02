#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n)
{
    vector< vector<int> > grid;
    int i,j,rtx,rty,lbx,lby;
    for(i=0;i<m;i++)
    {
        vector<int> row;
        row.assign(n,0);
        grid.push_back(row);
    }
    if(m==1||n==1) return 1;
    else
    {
        grid[m-1][n-2]=1;
        grid[m-2][n-1]=1;
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
                if(rtx+j+1>m-1)
                    grid[rtx+j][rty-j]=grid[rtx+j][rty-j+1];
                else if(rty-j+1>n-1)
                    grid[rtx+j][rty-j]=grid[rtx+j+1][rty-j];
                else if(rtx+j+1<=m-1&&rty-j+1<=n-1)
                    grid[rtx+j][rty-j]=grid[rtx+j][rty-j+1]+grid[rtx+j+1][rty-j];
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
    int m,n;
    fin>>m>>n;
    cout<<m<<' '<<n<<endl<<uniquePaths(m,n);
    return 0;
}
