#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

bool isValid(string s)
{
    vector<char> stk;
    int i,len=s.size();
    for(i=0;i<len;i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{') stk.push_back(s[i]);
        else if(s[i]==')')
        {
            if(stk.size()==0||stk[stk.size()-1]!='(') return false;
            stk.pop_back();
        }
        else if(s[i]==']')
        {
            if(stk.size()==0||stk[stk.size()-1]!='[') return false;
            stk.pop_back();
        }
        else if(s[i]=='}')
        {
            if(stk.size()==0||stk[stk.size()-1]!='{') return false;
            stk.pop_back();
        }
    }
    if(stk.size()!=0) return false;
    return true;
}

int main()
{
    ifstream fin("in.txt");
    string s;
    fin>>s;
    cout<<s<<endl;
    cout<<isValid(s);
    return 0;
}
