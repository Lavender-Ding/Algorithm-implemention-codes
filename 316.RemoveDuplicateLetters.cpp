#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

string removeDuplicateLetters(string s)
{
    string result;
    vector<char> uniqueChar;
    vector<int> cnt(256,0);
    vector<bool> isInStk(256,false);
    int i,j;
    for(i=0;i<s.size();i++) cnt[s[i]]++;
    for(i=0;i<s.size();i++)
    {
        for(j=uniqueChar.size()-1;j>=0&&!isInStk[s[i]]&&uniqueChar[j]>=s[i]&&cnt[uniqueChar[j]]>0;j--)
        {
            isInStk[uniqueChar[j]]=false;
            uniqueChar.pop_back();
        }
        cnt[s[i]]--;
        if(isInStk[s[i]]) continue;
        uniqueChar.push_back(s[i]);
        isInStk[s[i]]=true;
    }
    for(i=0;i<uniqueChar.size();i++) result+=uniqueChar[i];
    return result;
}

int main()
{
    ifstream fin("in.txt");
    string s;
    fin>>s;
    cout<<s<<endl;
    string result=removeDuplicateLetters(s);
    cout<<result;
    return 0;
}
