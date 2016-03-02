#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<string> > groupAnagrams(vector<string>& strings)
{
    map<string,int> smap;
    vector<vector<string> > result;
    int i,j,pos=0;
    for(i=0;i<strings.size();i++)
    {
        string key=strings[i];
        sort(key.begin(),key.end());
        if(!smap.count(key))
        {
            smap.insert(pair<string,int>(key,pos));
            pos++;
            vector<string> one;
            one.push_back(strings[i]);
            result.push_back(one);
        }
        else result[smap[key]].push_back(strings[i]);
    }
    for(i=0;i<result.size();i++) sort(result[i].begin(),result[i].end());
    return result;
}

int main()
{
    ifstream fin("in.txt");
    string str;
    vector<string> strings;
    while(!fin.eof())
    {
        fin>>str;
        strings.push_back(str);
    }
    for(int i=0;i<strings.size();i++) cout<<strings[i]<<' ';
    cout<<endl;
    vector<vector<string> > result=groupAnagrams(strings);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            for(int k=0;k<result[i][j].size();k++) cout<<result[i][j][k];
            cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
