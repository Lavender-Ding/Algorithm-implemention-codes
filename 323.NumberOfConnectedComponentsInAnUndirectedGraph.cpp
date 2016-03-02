#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int findParent(vector<int>& parent,int tmp)
{
    while(1)
    {
        if(parent[tmp]<0) return tmp;
        tmp=parent[tmp];
    }
}

int countComponents(int n, vector<pair<int, int> >& edges)
{
    vector<int> parent;
    parent.assign(n,-1);
    int i,x,y,num=0;
    for(i=0;i<edges.size();i++)
    {
        x=edges[i].first;
        y=edges[i].second;
        int px=findParent(parent,x),py=findParent(parent,y);
        if(px==py) continue;
        else if(px!=py)
        {
            if(parent[px]<parent[py])
            {
                parent[px]+=parent[py];
                parent[py]=px;
            }
            else
            {
                parent[py]+=parent[px];
                parent[px]=py;
            }
        }
    }
    for(i=0;i<parent.size();i++)
        if(parent[i]<0) num++;
    return num;
}

int main()
{
    ifstream fin("in.txt");
    int n;
    fin>>n;
    vector<pair<int,int> > edges;
    int x,y;
    while(!fin.eof())
    {
        fin>>x>>y;
        edges.push_back(pair<int,int>(x,y));
    }
    cout<<n<<endl<<endl;;
    for(int i=0;i<edges.size();i++) cout<<edges[i].first<<' '<<edges[i].second<<endl;
    cout<<endl;
    cout<<countComponents(n,edges);
    return 0;
}
