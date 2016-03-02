#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void findkelement(int n,int k,int head,vector<int> com,vector< vector<int> > &combination)
{
    int i,j,h;
    for(h=head;h<=n-k+1;h++)
    {
        com.push_back(h);
        if(k==1) combination.push_back(com);
        else findkelement(n,k-1,h+1,com,combination);
        com.pop_back();
    }
}

vector< vector<int> > combine(int n, int k)
{
    vector< vector<int> > combination;
    int head=1;
    vector<int> com;
    findkelement(n,k,head,com,combination);
    return combination;
}

int main()
{
    ifstream fin("in.txt");
    int n,k;
    fin>>n>>k;
    cout<<n<<' '<<k<<endl;
    vector< vector<int> > combination;
    combination=combine(n,k);
    for(int i=0;i<combination.size();i++)
    {
        for(int j=0;j<combination[i].size();j++) cout<<combination[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
