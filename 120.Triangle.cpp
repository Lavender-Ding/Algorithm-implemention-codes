#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int minimumTotal( vector <vector<int> >& triangle)
{
    int bottom=triangle.size()-1;
    int i,j;
    for(i=bottom-1;i>=0;i--)
    {
        for(j=0;j<triangle[i].size();j++)
        {
            if(triangle[i+1][j]<=triangle[i+1][j+1]) triangle[i][j]+=triangle[i+1][j];
            else triangle[i][j]+=triangle[i+1][j+1];
        }
    }
    return triangle[0][0];
}

int main()
{
    ifstream fin("in.txt");
    vector< vector<int> > triangle;
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
        if(ch=='\n') triangle.push_back(nums);
        if(ch==EOF)
        {
            triangle.push_back(nums);
            break;
        }
    }
    for(int i=0;i<triangle.size();i++)
    {
        for(int j=0;j<triangle[i].size();j++) cout<<triangle[i][j]<<' ';
        cout<<endl;
    }
    cout<<minimumTotal(triangle);
    return 0;
}
