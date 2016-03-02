#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    map<char,int> smap;
    int i=0,j=0,tmp,len=s.size(),maxLen=-1;;
    if(len==0) return 0;
    for(;j<len;j++)
    {
        if(smap.count(s[j]))
        {
            tmp=smap[s[j]];
            if(tmp>=i)
            {
                maxLen=max(maxLen,j-i);
                i=tmp+1;
            }
        }
        smap[s[j]]=j;
        cout<<i<<' '<<j<<endl;
    }
    maxLen=max(maxLen,j-i);
    return maxLen;
}

int main()
{
    ifstream fin("in.txt");
    string s;
    fin>>s;
    cout<<s<<endl;
    cout<<lengthOfLongestSubstring(s);
    return 0;
}
