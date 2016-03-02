#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>

using namespace std;

string minWindow(string s, string t)
{
    map<char,int> tmap;
    int i,j,tlen=t.size(),slen=s.size();minlen=slen+1,left=0,right=0;
    for(i=0;i<tlen;i++)
        if(!tmap.count(t[i])) tmap.insert(pair<char,int>(t[i],1));
    while(right<slen)
    {
        if()
    }
}

int main()
{
    ifstream fin("in.txt");
    string s,t;
    fin>>s>>t;
    cout<<s<<' '<<t<<endl;
    cout<<minWindow(s,t);
    return 0;
}
