#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> row;
vector<bool> col;
vector<bool> rl,lr;

void FindSolution(int k,int n,vector< vector<string> > &solution)
{
    int i,j,c;
    for(i=0;i<n;i++)
    {
        if(col[i]==false&&rl[n-1-k+i]==false&&lr[k+i]==false)
        {
            row[k]=i;
            col[i]=true;
            rl[n-1-k+i]=lr[k+i]=true;
            if(k==n-1)
            {
                vector<string> one;
                for(j=0;j<n;j++)
                {
                    string s;
                    for(c=0;c<n;c++) s=s+'.';
                    s[row[j]]='Q';
                    one.push_back(s);
                }
                solution.push_back(one);
            }
            else FindSolution(k+1,n,solution);
            col[i]=false;
            rl[n-1-k+i]=lr[k+i]=false;
        }
    }
}

vector< vector<string> > solveNQueens(int n)
{
    vector< vector<string> > solution;
    if(n==0) return solution;
    row.assign(n,0);
    col.assign(n,false);
    rl.assign(n+n-1,false);
    lr.assign(n+n-1,false);
    FindSolution(0,n,solution);
    return solution;
}

int main()
{
    ifstream fin("in.txt");
    int n;
    fin>>n;
    cout<<n<<endl;
    vector< vector<string> > solution;
    solution=solveNQueens(n);
    for(int i=0;i<solution.size();i++)
    {
        for(int j=0;j<solution[i].size();j++)
        {
            for(int k=0;k<solution[i][j].size();k++) cout<<solution[i][j][k];
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
