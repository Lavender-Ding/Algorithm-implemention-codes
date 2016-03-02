#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int maximalRectangle(vector<vector<char> >& matrix)
{
    if(matrix.size()==0) return 0;
    vector<vector<int> > hist;
    int row=matrix.size();
    int col=matrix[0].size();
    vector<int> tmp;
    tmp.assign(col,0);
    hist.assign(row,tmp);

    int i,j,cnt;
    for(i=0;i<col;i++)
    {
        cnt=0;
        for(j=row-1;j>=0;j--)
        {
            if(matrix[j][i]=='1') hist[j][i]=++cnt;
            else cnt=0;
        }
    }
    for(i=0;i<hist.size();i++)
    {
        for(j=0;j<hist[i].size();j++) cout<<hist[i][j]<<' ';
        cout<<endl;
    }

    int maxarea=0;
    int s,k;
    for(i=0;i<row;i++)
    {
        j=0;
        while(j<col)
        {
            if(hist[i][j]==0) j++;
            else
            {
                k=j+1;
                while(k<col&&hist[i][k]>=hist[i][j]) k++;
                s=j-1;
                while(s>=0&&hist[i][s]>=hist[i][j]) s--;
                int tmp=hist[i][j]*(k-s-1);
                if(tmp>maxarea) maxarea=tmp;
                while(j+1<col&&hist[i][j+1]==hist[i][j]) j++;
                j++;
            }
        }
    }

    return maxarea;
}

int main()
{
    ifstream fin("in.txt");
    vector<vector<char> > grid;
    char tmp;
    char ch;
    while(1)
    {
        vector<char> nums;
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
    cout<<endl;
    cout<<maximalRectangle(grid);
    return 0;
}
