#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> row;
vector<bool> col;
vector<bool> rl,lr;

void FindSolution(int k,int n,int &total)
{
    int i,j,c;
    for(i=0;i<n;i++)
    {
        if(col[i]==false&&rl[n-1-k+i]==false&&lr[k+i]==false)
        {
            row[k]=i;
            col[i]=true;
            rl[n-1-k+i]=lr[k+i]=true;
            if(k==n-1) total++;
            else FindSolution(k+1,n,total);
            col[i]=false;
            rl[n-1-k+i]=lr[k+i]=false;
        }
    }
}

int totalNQueens(int n)
{
    int total=0;
    if(n==0) return total;
    row.assign(n,0);
    col.assign(n,false);
    rl.assign(n+n-1,false);
    lr.assign(n+n-1,false);
    FindSolution(0,n,total);
    return total;
}

int main()
{
    ifstream fin("in.txt");
    int n;
    fin>>n;
    cout<<n<<endl;
    int total;
    total=totalNQueens(n);
    cout<<total;
    return 0;
}
